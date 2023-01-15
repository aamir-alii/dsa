// problem link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// kanh's algorithm (the idea here is we are checking if a vertix is visiting more than once by tracking indegree)
bool isCyclic(int V, vector<int> adj[]) {
        int count = 0;
        // for storing in-degree of each vertex
        vector<int> indegree(V,0);
        for (int u = 0; u < V; u++) { 
        for (int x:adj[u]) 
            indegree[x]++; 
    } 
        queue<int> q; 
    for (int i = 0; i < V; i++) 
// pushing only those vertices which are having no dependency or having zero indegree
        if (indegree[i] == 0) 
            q.push(i); 
            // if an element is push into stack only once then the number of vertices and
            // number of time loops run will be equal so we are counting loop count;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto x: adj[u]){
                if (--indegree[x] == 0) 
                q.push(x); 
            }
            //updating loop count
        count++;
        }
        // checking if loop count equals no of vertices
        return count != V;
    }