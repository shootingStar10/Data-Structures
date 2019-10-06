#include <bits/stdc++.h>

using namespace std;

int solve(int a[], int lo, int hi)
{
   if (lo > hi) {
    return 0;
   }

   if (lo == hi) {
    return lo;
   }

   int mid = (lo+hi)/2;

   if (mid < hi && a[mid+1] < a[mid]) {
    return mid+1;
   }

   if (mid > lo && a[mid] < a[mid-1]) {
    return mid;
   }

   if (a[mid] < a[hi]) {
    return solve(a, lo, mid-1);
   }

   return solve(a, mid+1, hi);
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

        cout<<solve(a, 0, n-1)<<endl;
    }

    return 0;
}

/*
Time complexity: O(logN)
*/
