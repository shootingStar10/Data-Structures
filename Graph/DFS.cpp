#include <bits/stdc++.h>

using namespace std;

void DFS(vector <int> G[], int V, int start)
{
    stack <int> s;
    bool visited[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    s.push(start);
    visited[start] = true;

    while (s.empty() == false) {
        int x = s.top();
        s.pop();
        cout<<x<<" ";

        for (int i = 0; i < G[x].size(); i++) {
            if (visited[G[x][i]] == false) {
                s.push(G[x][i]);
                visited[G[x][i]] = true;
            }
        }
    }
}

int main()
{
    int V, E, u, v, t;

    cin>>t;

    while (t--) {
        cin>>V>>E;

        vector <int> G[V];

        for (int i = 0; i < E; i++) {
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        DFS(G, V, 0);
        cout<<endl;
    }

    return 0;
}

/*
2
5 4
0 1 0 2 0 3 2 4
3 2
0 1 0 2

Time Complexity: O(V+E)
*/
