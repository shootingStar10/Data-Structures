#include <bits/stdc++.h>

using namespace std;

struct node
{
    bool EOW;
    struct node *children[26];
};

struct node *root;

struct node *createNode()
{
    struct node *newNode = new node;

    newNode->EOW = false;

    for (int i = 0; i < 26; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
};

void insert(string word)
{
    struct node *temp = root;

    for (int i = 0; i < word.length(); i++) {
        int j = word[i] - 'a';

        if (temp->children[j] == NULL) {
            temp->children[j] = createNode();
        }

        temp = temp->children[j];
    }

    temp->EOW = true;
}

bool search(string word)
{
    struct node *temp = root;

    for (int i = 0; i < word.length(); i++) {
        int j = word[i] - 'a';

        if (temp->children[j] == NULL) {
            return false;
        }

        temp = temp->children[j];
    }

    return (temp != NULL && temp->EOW);
}

int main()
{
    root = createNode();

    insert("boxing");
    insert("boxer");
    insert("box");
    insert("inbox");

    cout<<search("box")<<endl;
    cout<<search("boxing")<<endl;
    cout<<search("boxx")<<endl;
    cout<<search("xyz")<<endl;

    return 0;
}

/*

Time Complexity: O(N) both for insert and search where N is word length.

Space Complexity: O(26*N*M) where N is word length and M is number of words.

*/
