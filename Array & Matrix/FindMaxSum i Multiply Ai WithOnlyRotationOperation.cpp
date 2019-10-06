/*
Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we want.
Return the maximum possbile of summation of i*arr[i].
*/

#include <bits/stdc++.h>

using namespace std;

int solve(int a[], int n)
{
    int sum = 0, curr_val = 0, max_val;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        curr_val += (i*a[i]);
    }

    max_val = curr_val;

    for (int i = 1; i < n; i++) {
        curr_val = curr_val - sum + (n*a[i-1]);

        if (curr_val > max_val) {
            max_val = curr_val;
        }
    }

    return max_val;
}

int main()
{
    int t, n;

    cin>>t;

    while (t--) {
        cin>>n;
        int a[n];

        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }

        cout<<solve(a, n)<<endl;
    }

    return 0;
}

/*
Time complexity: O(N)
*/
