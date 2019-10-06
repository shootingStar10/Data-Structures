#include <bits/stdc++.h>

using namespace std;

int a[10000003];

int solve(int n, int k, int lo, int hi)
{
    if (lo <= hi) {
        int mid = (lo+hi)/2;

        if (a[mid] == k) {
            return mid;
        }

        if (a[lo] <= a[mid]) {
            if (k >= a[lo] && k <= a[mid]) {
                return solve(n, k, lo, mid-1);
            }
            return solve(n, k, mid+1, hi);
        }

        if (k >= a[mid] && k <= a[hi]) {
            return solve(n, k, mid+1, hi);
        }

        return solve(n, k, lo, mid-1);
    }

    return -1;
}

int main()
{
    int t, n, k;

    cin>>t;

    while (t--) {
        cin>>n;

        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }

        cin>>k;
        cout<<solve(n, k, 0, n-1)<<endl;
    }

    return 0;
}

/*
Time complexity: O(logN)
*/

