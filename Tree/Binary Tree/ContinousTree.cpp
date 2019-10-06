/*
A tree is Continuous tree if in each root to leaf path, absolute difference between keys of two adjacent is 1.
We are given a binary tree, we need to check if tree is continuous or not.
*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create_node(int val)
{
    struct node *root = new node;
    root->data = val;
    root->left = NULL;
    root->right = NULL;

    return root;
};

bool solve(struct node *root)
{
    if (root == NULL) {
        return true;
    }

    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    if (root->left == NULL) {
        return (abs(root->data - root->right->data) == 1 && solve(root->right));
    }

    if (root->right == NULL) {
        return (abs(root->data - root->left->data) == 1 && solve(root->left));
    }

    return abs(root->data - root->left->data) == 1 && abs(root->data - root->right->data) == 1 &&
           solve(root->left) && solve(root->right);
}

int main()
{
    struct node *root = create_node(3);
    root->left = create_node(2);
    root->right = create_node(4);
    root->left->left = create_node(1);
    root->left->right = create_node(3);
    root->right->right = create_node(5);

    string ans = (solve(root) == true) ? "continous" : "discontinous";
    cout<<ans<<endl;

    return 0;
}
