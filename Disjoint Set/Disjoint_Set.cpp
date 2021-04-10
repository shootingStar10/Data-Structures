#include <bits/stdc++.h>

using namespace std;

int N, Rank[100], Parent[100];

void make_set()
{
    for (int i = 0; i < N; i++) {
        Rank[i] = 1;
        Parent[i] = i;
    }
}

int find_set(int x)
{
    if (x != Parent[x]) {
        Parent[x] = find_set(Parent[x]);
    }

    return Parent[x];
}

void _union(int x, int y)
{
    int par_x = find_set(x);
    int par_y = find_set(y);

    if (par_x == par_y) {
        return;
    }

    if (Rank[par_x] < Rank[par_y])
    {
        Parent[par_x] = par_y;
    }
    else if (Rank[par_x] > Rank[par_y])
    {
        Parent[par_y] = par_x;
    }
    else
    {
        Parent[par_y] = par_x;
        Rank[par_x]++;
    }
}

int main()
{
    N = 5;

    make_set();
    _union(0, 2);
    _union(4, 2);
    _union(3, 1);

    if (find_set(4) == find_set(0))
        cout << "Yes\n";
    else
        cout << "No\n";

    if (find_set(1) == find_set(0))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
