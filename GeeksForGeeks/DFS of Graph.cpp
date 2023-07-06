// Problem Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// Concepts: Graph,BFS

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[],vector<bool> &visited,vector<int> &ans,int i,int V){
        if(i>V) return;
        if(visited[i])  return;
        
        visited[i]=true;
        ans.push_back(i);
        for(auto curr: adj[i]){
            if(!visited[curr])  dfs(adj,visited,ans,curr,V);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> visited(V,false);
        dfs(adj,visited,ans,0,V);
        return ans;
    }
};