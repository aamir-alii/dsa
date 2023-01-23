// https://leetcode.com/problems/all-paths-from-source-to-target/description/
void dfsRec(int target, vector<vector<int>> &paths, vector<vector<int>> &graph, int curr, vector<int> &path)
{
    if (curr == target)
    {
        // if we found path to target
        paths.push_back(path);
        return;
    }
    for (auto x : graph[curr])
    {
        // adding this node to path
        path.push_back(x);
        // calling for node neighbour
        dfsRec(target, paths, graph, x, path);
        // backtracking (removing curr node neighbour from path)
        path.pop_back();
        // making curr node unvisited
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> path;
    vector<vector<int>> paths;
    path.push_back(0);
    dfsRec(V - 1, paths, graph, 0, path);
    return paths;
}