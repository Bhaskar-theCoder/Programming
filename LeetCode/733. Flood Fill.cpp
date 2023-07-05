// Problem Link: https://leetcode.com/problems/flood-fill/description/

// Concepts: DFS

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
    void dfs(vector<vector<int>> &image, int sr, int sc, int color,int c){
        if(sr>=image.size()||sc>=image[0].size()||sr<0||sc<0)   return;
        if(image[sr][sc]==color)    return;

        if(image[sr][sc]==c){
            image[sr][sc]=color;
            int a[4]={0,1,0,-1};
            int b[4]={1,0,-1,0};
            for(int i=0;i<4;i++)    dfs(image,sr+a[i],sc+b[i],color,c);
        }
    }
};