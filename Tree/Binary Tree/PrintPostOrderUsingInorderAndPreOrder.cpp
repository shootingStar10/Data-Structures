/*
Given inorder & preorder traversal of a binary tree. Print it's postorder traversal without creating the tree.
*/

#include <bits/stdc++.h>

using namespace std;

int _search(int a[], int key, int lo, int hi)
{
    for (int i = lo; i < hi; i++) {
        if (a[i] == key) {
            return i;
        }
    }

    return hi;
}

int i;

void solve(int pre[], int in[], int lo, int hi)
{
    if (lo > hi) {
        return;
    }

    int j = _search(in, pre[i++], lo, hi);

    solve(pre, in, lo, j-1);
    solve(pre, in, j+1, hi);
    cout<<in[j]<<" ";
}

int main()
{
    int t, n;

    cin>>t;

    while (t--) {
        cin>>n;
        int pre[n], in[n];

        for (int i = 0; i < n; i++) {
            cin>>pre[i];
            in[i] = pre[i];
        }

        sort(in, in+n);
        i = 0;
        solve(pre, in, 0, n-1);
        cout<<endl;
    }

    return 0;
}

/*
1
5
40 30 35 80 100

Time complexity: O(N)
*/
