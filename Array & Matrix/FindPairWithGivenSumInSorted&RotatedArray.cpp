#include <bits/stdc++.h>

using namespace std;

bool solve(int a[], int n, int sum)
{
    int l, r = 0, maximum = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > maximum) {
            maximum = a[i];
            r = i;
        }
    }

    l = (r+1)%n;

    while (l != r) {
        if (a[l] + a[r] == sum) {
            return true;
        } else if (a[l] + a[r] < sum) {
            l = (l+1)%n;
        } else {
            r = (r == 0) ? n-1 : r-1;
        }
    }

    return false;
}

int main()
{
    int t, n, x;

    cin>>t;

    while (t--) {
        cin>>n;
        int a[n];

        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }

        cin>>x;
        char ans = (solve(a, n, x) == true) ? 'T' : 'F';

        cout<<ans<<endl;
    }

    return 0;
}

/*
Time complexity: O(N)
*/
