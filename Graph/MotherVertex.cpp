/*
A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be reached by a path from v.
*/

#include <bits/stdc++.h>

using namespace std;

void DFS(vector <int> G[], int i, bool visited[])
{
    visited[i] = true;

    for (int j = 0; j < G[i].size(); j++) {
        if (visited[G[i][j]] == false) {
            DFS(G, G[i][j], visited);
        }
    }
}

int solve(vector <int> G[], int V)
{
    bool visited[V];
    int v;

    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            DFS(G, i, visited);
            v = i;
        }
    }

    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    DFS(G, v, visited);

    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            return -1;
        }
    }

    return v;
}

int main()
{
    int V, E, x, y;

    cin>>V>>E;
    vector <int> G[V];

    for (int i = 0; i < E; i++) {
        cin>>x>>y;
        G[x].push_back(y);
    }

    cout<<solve(G, V)<<endl;

    return 0;
}

/*
7 8
0 1
0 2
1 3
4 1
5 2
5 6
6 0
6 4

Time complexity: O(V+E)
Space complexity: O(V+E)
*/
