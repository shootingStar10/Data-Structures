#include<bits/stdc++.h>
using namespace std;
struct et
{
	char value;
	et* left, *right;

	et(char x){
	    value = x;
	    left = right = NULL;
	}
};
bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}
void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}
et* constructTree(char []);
int main()
{
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*struct et
{
	char value;
	et* left, *right;
};*/

et * create_node (char key)
{
    et *root = new et(key);

    return root;
}

//function to construct expression tree
et* constructTree(char postfix[])
{
    //code here
    stack <et* > s;
    int n = strlen(postfix);

    for (int i = 0; i < n; i++) {
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' ||
            postfix[i] == '/' || postfix[i] == '^')
        {
            et * temp1 = s.top();
            s.pop();

            et * temp2 = s.top();
            s.pop();

            et * temp = create_node(postfix[i]);
            temp->right = temp1;
            temp->left = temp2;

            s.push(temp);
        } else {
            et *temp = create_node(postfix[i]);
            s.push(temp);
        }
    }

    return s.top();
}
