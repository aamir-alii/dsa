vector<int> topoSort(int V, vector<int> adj[]) 
	{
        // finding indegree of each vertix
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto j: adj[i]){
	            indegree[j]++;
	        }
	    }
        // creating an array to store res
	    vector<int> ans;
        // creating a queue to store elements based on its indegree
        // if indegree of an element is 0 push it to queue
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        ans.emplace_back(u);
	        for(auto x: adj[u]){
                // while we visit it's parent we want to decrese its indegree by one
	            indegree[x]--;
                // if indegree become zero its mean that we visit each depenedency of a vertix
                // and we now good to add it to queue
	            if(indegree[x] == 0)
	                q.push(x);
	        }
	    }
	    return ans;
	}