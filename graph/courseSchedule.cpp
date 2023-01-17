// problem link: https://leetcode.com/problems/course-schedule/description/
bool dfsRec(int s, vector<bool> &visited, vector<bool> &recStack, vector<int> adj[])
{
    // mark current node as true
    visited[s] = true;
    recStack[s] = true;
    // visiting all neighbours of s node
    for (auto x : adj[s])
    {
        // if current element is not visited and x node has cycle then return true
        if (!visited[x] && dfsRec(x, visited, recStack, adj))
            return true;
        else if (recStack[x]) // if current node is already in recStack means that there is cycle in graph
            return true;
    }
    // backtracking // removing s node from recStack
    return recStack[s] = false;
}
bool canFinish(int n, vector<vector<int>> &prerequisites)
{
    // creating adj list
    vector<int> adj[n];
    for (int i = 0; i < prerequisites.size(); i++)
    {
        auto data = prerequisites[i];
        int u = data[0];
        int v = data[1];
        adj[u].push_back(v);
    }

    vector<bool> visited(n, false), recStack(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            // if cycle is present return false
            if (dfsRec(i, visited, recStack, adj))
            {
                return false;
            }
    }
    // no cycle present
    return true;
}