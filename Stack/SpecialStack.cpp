#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function(s) below*/
stack <int> minStack;
void push(int a)
{
     //add code here.
     s.push(a);

     if (minStack.empty() == true) {
         minStack.push(a);
     } else {
         if (a < minStack.top()) {
             minStack.push(a);
         } else {
             minStack.push(minStack.top());
         }
     }
}
bool isFull(int n)
{
     //add code here.
     return (s.size() == n);
}
bool isEmpty()
{
    //add code here.

    return (s.size() == 0);
}
int pop()
{
    //add code here.
    minStack.pop();
    int retVal = s.top();
    s.pop();

    return retVal;
}
int getMin()
{
   //add code here.
   return minStack.top();
}
