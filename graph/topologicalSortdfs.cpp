//problem link: https://practice.geeksforgeeks.org/problems/topological-sort/1
void topoRec(int node, stack<int> &s, vector<bool> &vis, vector<int> adj[]){
	    vis[node] = true;
	   // visiting each neighbour nodes
	   for(auto x: adj[node]){
	       if(!vis[x]){
	           topoRec(x,s,vis,adj);
	       }
	   }
    //    proccessing current node
	   s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   stack<int> s;
	   vector<bool> vis(V);
	   vector<int> ans;
	   //visiting each and every component in case of disconnected graph
	   for(int i=0;i<V;i++){
	       //calling Recursive function to store data in stack if not visited
	       if(!vis[i])
	        topoRec(i,s,vis,adj);
	   }
	   while(!s.empty()){
	       int top = s.top();
	       ans.push_back(top);
	       s.pop();
	   }
	   return ans;
	}