#include <bits/stdc++.h>

using namespace std;

vector <int> g[1000];
int v;

void dfs(vector <int> g[], int i, bool visited[], stack <int> &s)
{
    if (visited[i] == true) {
        return;
    }

    visited[i] = true;

    for (int j = 0; j < g[i].size(); j++) {
        dfs(g, g[i][j], visited, s);
    }

    s.push(i);
}

void dfs2(vector <int> g[], int i, bool visited[])
{
    if (visited[i] == true) {
        return;
    }

    visited[i] = true;
    cout<<i<<" ";

    for (int j = 0; j < g[i].size(); j++) {
        dfs2(g, g[i][j], visited);
    }
}

void findSCC(vector <int> g[], int v)
{
    bool visited[v];
    stack <int> s;

    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++) {
        if (visited[i] == false) {
            dfs(g, i, visited, s);
        }
    }

    vector <int> gt[v];

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            gt[g[i][j]].push_back(i);
        }
    }

    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }

    while (s.empty() == false) {
        int x = s.top();
        s.pop();

        if (visited[x] == false) {
            dfs2(gt, x, visited);
            cout<<endl;
        }
    }
}

int main()
{
    v = 5;

    g[0].push_back(2);
    g[0].push_back(3);

    g[1].push_back(0);

    g[2].push_back(1);

    g[3].push_back(4);

    findSCC(g, v);

    return 0;
}
