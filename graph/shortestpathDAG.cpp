// problem link: https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// using topological sort method
void makeAdj(vector<vector<pair<int, int>>> &adj, vector<vector<int>> &edges, int E)
{
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back(make_pair(v, w));
    }
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(N);
    vector<int> dist(N, -1);
    dist[0] = 0;
    makeAdj(adj, edges, M);
    vector<int> indegree(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j.first]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (!indegree[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto x : adj[u])
        {
            if (dist[u] != -1)
            {
                if (dist[x.first] != -1)
                    dist[x.first] = min(dist[u] + x.second, dist[x.first]);
                else
                    dist[x.first] = dist[u] + x.second;
            }
            indegree[x.first]--;
            if (!indegree[x.first])
                q.push(x.first);
        }
    }
    return dist;
}