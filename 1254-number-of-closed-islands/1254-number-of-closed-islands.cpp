class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()||grid[i][j]==1 || grid[i][j]==-1){
            return;
        }
        grid[i][j]=-1;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    
    void dfs1(int i, int j, vector<vector<int>>&grid){
        if(i<0 ||j<0 || i>=grid.size()||j>=grid[0].size() || grid[i][j]==1 || grid[i][j]==-1||grid[i][j]==2){
            return;
        }
        grid[i][j]=2;
        dfs1(i+1,j,grid);
        dfs1(i-1,j,grid);
        dfs1(i,j+1,grid);
        dfs1(i,j-1,grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1){
                    if(grid[i][j]==0){
                        dfs(i,j,grid);
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    dfs1(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};