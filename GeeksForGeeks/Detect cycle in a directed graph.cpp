// Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// Concepts: Graph,DFS

class Solution {
  public:
    bool solve(int i,vector<int> adj[],vector<bool> &visited,vector<bool> &dfsVisited){
        visited[i]=true;
        dfsVisited[i]=true;
        
        for(auto v:adj[i]){
            if(!visited[v]){
                if(solve(v,adj,visited,dfsVisited)) return true;
            }
            else if(dfsVisited[v])  return true;
        }
        dfsVisited[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<bool> dfsVisited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(solve(i,adj,visited,dfsVisited)) return true;
            }
        }
        return false;
    }
};