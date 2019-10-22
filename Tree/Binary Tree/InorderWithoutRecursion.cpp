#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    struct node *left, *right;
};

struct node *createNode(int key)
{
    struct node *root = new node;
    root->val = key;
    root->left = NULL;
    root->right = NULL;

    return root;
};

void printInorder(struct node *root)
{
    stack <struct node*> s;

    while (root != NULL || s.empty() == false) {
        if (root == NULL) {
           struct node *temp = s.top();
           s.pop();

           cout<<temp->val<<" ";
           root = temp->right;
        } else {
            s.push(root);
            root = root->left;
        }
    }

    cout<<endl;
}

int main()
{
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->right = createNode(5);

    printInorder(root);

    return 0;
}

/*
Time complexity: O(N)
Space complexity: O(N)
*/
