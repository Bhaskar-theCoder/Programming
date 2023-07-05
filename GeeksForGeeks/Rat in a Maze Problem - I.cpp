// Problem Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// Concepts : Backtracking

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string curr = "";
        dfs(m,n,curr,ans,0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
    void dfs(vector<vector<int>> &m, int n,string &curr,vector<string> &ans,int i,int j){
        
        if(m[i][j]==0)  return;
        if(i==n-1&&j==n-1){ ans.push_back(curr);    return;}
        m[i][j]=-1;
        int a[4]={0,1,0,-1};
        int b[4]={1,0,-1,0};
        char dirs[4]={'R','D','L','U'};
        
        for(int t=0;t<4;t++){
            if(i+a[t]>=0&&j+b[t]>=0&&i+a[t]<n&&j+b[t]<n&&m[i+a[t]][j+b[t]]==1){
                string newString=curr+dirs[t];
                dfs(m,n,newString,ans,i+a[t],j+b[t]);
            }
        }
        
        m[i][j]=1;
    }
};