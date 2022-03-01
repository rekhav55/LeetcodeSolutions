class Solution {
public:
    void dfs(int row,int col, vector<vector<int>>&visited, vector<vector<char>>&grid){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]=='0' || visited[row][col]==1){
            return;
        }
        visited[row][col]=1;
        dfs(row+1,col,visited,grid);
        dfs(row-1,col,visited,grid);
        dfs(row,col+1,visited,grid);
        dfs(row,col-1,visited,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    dfs(i,j,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
};