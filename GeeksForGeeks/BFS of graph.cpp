// Problem Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/0

// Concepts: Graphs,BFS

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> ans;
        vector<bool> visited(V,false);
        q.push(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited[curr]=true;
            for(auto i: adj[curr]){
                if(!visited[i]){ q.push(i); visited[i]=true;}
            }
            ans.push_back(curr);
        }
        return ans;
    }
};