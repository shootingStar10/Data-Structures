/*
Given a directed graph, find out if a vertex v is reachable from another vertex u for all vertex pairs (u, v) in the
given graph. Here reachable mean that there is a path from vertex u to v. The reach-ability matrix is
called transitive closure of a graph.
*/

#include <bits/stdc++.h>

using namespace std;

void DFS(vector <int> G[], int i, bool visited[], int tc[][50], int x)
{
    visited[i] = true;
    tc[x][i] = 1;

    for (int j = 0; j < G[i].size(); j++) {
        if (visited[G[i][j]] == false) {
            DFS(G, G[i][j], visited, tc, x);
        }
    }
}

void solve(vector <int> G[], int V)
{
    int tc[50][50];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            tc[i][j] = 0;
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            visited[j] = false;
        }
        DFS(G, i, visited, tc, i);
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout<<tc[i][j]<<" ";
        }
        cout<<endl;
    }
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

    solve(G, V);

    return 0;
}

/*
4 6
0 1
0 2
1 2
2 0
2 3
3 3

Time complexity: O(V^3)
but this can be optimized to O(V^2) by  Floyd Warshall Algorithm.
*/
