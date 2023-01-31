// problem lik: https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977
#include <bits/stdc++.h>
using namespace std;
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{

    // creating adjList
    vector<list<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int s = edges[i][0];
        int d = edges[i][1];
        int wt = edges[i][2];
        adj[s].push_back(make_pair(d, wt));
    }
    // loop from 1 to v - 1;
    vector<int> dist(n + 1, 1000000000);
    // dist from src to src is zero
    dist[src] = 0;
    for (int k = 1; k < n; k++)
    {
        // visiting each node
        for (int i = 1; i <= n; i++)
        {
            // calculating dist for all the neighbours
            for (auto x : adj[i])
            {
                if (dist[i] != 1000000000 && x.second + dist[i] < dist[x.first])
                {
                    dist[x.first] = x.second + dist[i];
                }
            }
        }
    }
    return dist[dest];
}