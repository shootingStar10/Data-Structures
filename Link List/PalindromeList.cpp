#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *create_node(int key)
{
    struct Node *node = new Node();
    node->data = key;
    node->next = NULL;

    return node;
}

void print_list(struct Node *head)
{
    struct Node *temp = head;
    int cnt = 6;

    while (temp != NULL && cnt > 0) {
        cout<<temp->data<<" ";
        temp = temp->next;
        cnt--;
    }

    cout<<endl;
}

bool isPalindrome(Node *head)
{
    //Your code here
    if (head == NULL) {
        return true;
    }

    struct Node *slow = head, *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node *c, *p, *n;
    c = slow->next;
    p = NULL;


    while (c != NULL) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }

    slow->next = p;

    print_list(head);

    c = slow->next;
    n = head;

    while (c != NULL) {
        if (c->data != n->data) {
            return false;
        }
        c = c->next;
        n = n->next;
    }

    return true;
}

int main()
{
    struct Node *head;

    head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(2);
    head->next->next->next = create_node(1);

    cout<<isPalindrome(head)<<endl;

    return 0;
}
