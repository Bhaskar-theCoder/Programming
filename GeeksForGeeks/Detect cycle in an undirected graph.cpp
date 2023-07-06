// Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Concepts Graph,DFS,BFS

// Method 1: Recursive DFS
class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
        
        unordered_map<int,bool> visited;

        for(int i=0;i<V;i++){
            if(!visited[i])
                if(isCyclic(i,adj,visited,-1)) return true;
        }        
        return false;
    }
    
    bool isCyclic(int i,vector<int> adj[],unordered_map<int,bool> &visited,int parent){
        visited[i]=true;
        
        for(auto curr: adj[i]){
            if(!visited[curr]){
                if(isCyclic(curr,adj,visited,i))    return true;
            }
            else{
                if(parent!=curr)    return true;
            }
        }
        return false;
    }
};

// Method 2: BFS
class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
        
        unordered_map<int,bool> visited;

        for(int i=0;i<V;i++){
            if(!visited[i])
                if(isCyclic(i,adj,visited)) return true;
        }        
        return false;
    }
    
    bool isCyclic(int i,vector<int> adj[],unordered_map<int,bool> &visited){
        
        visited[i]=true;
        
        unordered_map<int,int> parent;
        parent[i]=-1;
        
        queue<int> q;
        q.push(i);
        
        while(!q.empty()){
            int v=q.front();
            q.pop();
            
            for(int curr:adj[v]){
                
                if(!visited[curr]){
                    q.push(curr);
                    parent[curr]=v;
                    visited[curr]=true;
                }
                else if(visited[curr]&&curr!=parent[v]) return true;
            }
        }
        return false;
    }