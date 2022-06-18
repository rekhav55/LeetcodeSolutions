class Solution {
public:
    int f(int i, int j, vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return 0;
        int temp = grid[i][j];
        grid[i][j]=0;
        int left = temp + f(i,j-1,grid);
        int right = temp + f(i,j+1,grid);
        int up= temp+f(i-1,j,grid);
        int down = temp + f(i+1,j,grid);
        grid[i][j]=temp;
        return max({up,down,left,right});
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int res=INT_MIN;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>mat;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0){
                    mat=grid;
                    int ans = f(i,j,mat);
                    res=max(res,ans);
                }
            }
        }
        if(res==INT_MIN) return 0;
        return res;
    }
};