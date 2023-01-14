// https://leetcode.com/problems/all-paths-from-source-to-target/description/
 void dfsRec(int target, vector<bool> &visited,vector<vector<int>> &paths,vector<vector<int>>& graph,int curr, vector<int> &path){
        if(curr == target){
            // if we found path to target
            paths.push_back(path);
            return;
        }
        for(auto x: graph[curr]){
            // if x is not visited currently
            if(!visited[x])
            {
                // making parent visited
                visited[curr] = true;
                // adding this node to path
                path.push_back(x);
                // calling for node neighbour
                dfsRec(target,visited,paths,graph,x,path);
                // backtracking (removing curr node neighbour from path)
                path.pop_back();
                // making curr node unvisited
                visited[curr] = false;
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V);
        vector<int> path;
        vector<vector<int>> paths;
        path.push_back(0);
        dfsRec(V-1,visited,paths,graph,0,path);
        return paths;
    }