/*
Given an array that represents Inorder Traversal, find all possible Binary Trees with the given Inorder traversal
and print their preorder traversals.
*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    struct node *left, *right;
};

struct node * createNode(int key)
{
    struct node *root = new node;
    root->val = key;
    root->left = NULL;
    root->right = NULL;

    return root;
};

void preOrderTraversal(struct node *root)
{
    if (root == NULL) {
        return;
    }

    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

vector <struct node*> solve(int a[], int lo, int hi)
{
    vector <struct node*> v;

    if (lo > hi) {
        v.push_back(NULL);
        return v;
    }

    for (int i = lo; i <= hi; i++) {
        vector <struct node*> lTree = solve(a, lo, i-1);
        vector <struct node*> rTree = solve(a, i+1, hi);

        for (int j = 0; j < lTree.size(); j++) {
            for (int k = 0; k < rTree.size(); k++) {
                struct node* root = createNode(a[i]);
                root->left = lTree[j];
                root->right = rTree[k];
                v.push_back(root);
            }
        }
    }

    return v;
}

int main()
{
    int a[] = {4, 5, 7};
    int n = 3;
    vector <struct node*> v;

    v = solve(a, 0, n-1);

    for (int i = 0; i < v.size(); i++) {
        preOrderTraversal(v[i]);
        cout<<endl;
    }

    return 0;
}
