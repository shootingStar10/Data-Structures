#include <bits/stdc++.h>

using namespace std;

void BFS(vector <int> G[], int V, int start)
{
    queue <int> q;
    bool visited[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    q.push(start);
    visited[start] = true;

    while (q.empty() == false) {
        int x = q.front();
        q.pop();
        cout<<x<<" ";

        for (int i = 0; i < G[x].size(); i++) {
            if (visited[G[x][i]] == false) {
                q.push(G[x][i]);
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
        }

        BFS(G, V, 0);
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
