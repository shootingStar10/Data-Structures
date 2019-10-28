/*
Given an unsorted integer array, find the smallest missing positive integer.
*/

#include <bits/stdc++.h>

using namespace std;

int solve(int a[], int n)
{
    int i = 0, j = 0;

    while (j < n) {
        if (a[j] <= 0) {
            swap(a[i], a[j]);
            i++;
        }

        j++;
    }

    int size = j-i;
    a = a+i;

    for (j = 0; j < size; j++) {
        if (abs(a[j])-1 < size && a[abs(a[j])-1] > 0) {
            a[abs(a[j])-1] = -a[abs(a[j])-1];
        }
    }

    for (j = 0; j < size; j++) {
        if (a[j] > 0) {
            return j+1;
        }
    }

    return size+1;
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
Time Complexity: O(N)
*/

