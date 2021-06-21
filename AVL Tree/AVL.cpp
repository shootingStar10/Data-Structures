#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    struct node *left, *right;
    int height;
};

struct node *create_node(int val)
{
    struct node *root = new node();
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    root->height = 1;

    return root;
}

int height(struct node *root)
{
    if (root == NULL) {
        return 0;
    }

    return root->height;
}

struct node *right_rotate(struct node *root)
{
    struct node *new_root = root->left;
    struct node *temp = new_root->right;

    new_root->right = root;
    root->left = temp;

    root->height = max(height(root->left), height(root->right))+1;
    new_root->height = max(height(new_root->left), height(new_root->right))+1;

    return new_root;
}

struct node *left_rotate(struct node *root)
{
    struct node *new_root = root->right;
    struct node *temp = new_root->left;

    new_root->left = root;
    root->right = temp;

    root->height = max(height(root->left), height(root->right))+1;
    new_root->height = max(height(new_root->left), height(new_root->right))+1;

    return new_root;
}

struct node *insert_key(struct node *root, int key)
{
    if (root == NULL) {
        return create_node(key);
    }

    if (key < root->val) {
        root->left = insert_key(root->left, key);
    } else {
        root->right = insert_key(root->right, key);
    }

    root->height = max(height(root->left), height(root->right))+1;

    int balance = height(root->left) - height(root->right);

    if (balance > 1) {
        if (height(root->left->left) >= height(root->left->right)) {
            return right_rotate(root);  // LL case
        } else {
            root->left = left_rotate(root->left);
            return right_rotate(root);      // LR case
        }
    } else if (balance < -1) {
        if (height(root->right->right) >= height(root->right->left)) {
            return left_rotate(root);   // RR case
        } else {
            root->right = right_rotate(root->right);
            return left_rotate(root);   // RL case
        }
    }

    return root;
}

void preorder_traverse(struct node *root)
{
    if (root == NULL) {
        return;
    }

    cout<<root->val<<" ";
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

int main()
{
    struct node *root = NULL;

    for (int i = 1; i <= 7; i++) {
        root = insert_key(root, i);
    }

    preorder_traverse(root);
    cout<<endl;

    return 0;
}
