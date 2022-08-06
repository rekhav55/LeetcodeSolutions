class Solution {
public:
    // int f(int row, int col, int desrow, int descol, vector<vector<int>>&grid, vector<vector<int>>&vis,int k,vector<vector<vector<int>>>&dp){
    //     if(k<0 || row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || vis[row][col]==1) return 1e9;
    //     if(row==desrow && col==descol) return 0;
    //     if(dp[row][col][k]!=-1) return dp[row][col][k];
    //     vis[row][col]=1;
    //     int up=0,down=0,left=0,right=0;
    //     if(grid[row][col]==0){
    //         up=1+f(row-1,col,desrow,descol,grid,vis,k,dp);
    //         down=1+f(row+1,col,desrow,descol,grid,vis,k,dp);
    //         left=1+f(row,col-1,desrow,descol,grid,vis,k,dp);
    //         right=1+f(row,col+1,desrow,descol,grid,vis,k,dp);
    //     }
    //     else{
    //         up=1+f(row-1,col,desrow,descol,grid,vis,k-1,dp);
    //         down=1+f(row+1,col,desrow,descol,grid,vis,k-1,dp);
    //         left=1+f(row,col-1,desrow,descol,grid,vis,k-1,dp);
    //         right=1+f(row,col+1,desrow,descol,grid,vis,k-1,dp);
    //     }
    //     vis[row][col]=0;
    //     return dp[row][col][k]=min({up,left,down,right});
    // }
    // int shortestPath(vector<vector<int>>& grid, int k) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vector<vector<int>>vis(n,vector<int>(m,0));
    //     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
    //     int ans = f(0,0,n-1,m-1,grid,vis,k,dp);
    //     if(ans>=1e9) return -1;
    //     return ans;
    // }
    vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};

int shortestPath(vector<vector<int>>& grid, int k) {
    
    int m = grid.size(),n = grid[0].size(), i,j, steps = 0;
    
    queue<vector<int>> q;
    
    bool visited[m][n][k+1];
    
    memset(visited,false,sizeof(visited));
    
    q.push({0,0,k});
     
    visited[0][0][k] = true;
    
    
    while(!q.empty())
    {
        int size = q.size();
        
        while(size--)
        {
            auto cur = q.front( );
            
            q.pop( );
            
            if(cur[0] == m-1 && cur[1] == n-1)
            {
                return steps;
            }
            
            for(auto x: dir)
            {
                int i = cur[0]+x[0];
                int j = cur[1] + x[1];
                int obs = cur[2];
                
                if(i>=0 && i<m && j>=0 && j<n)
                {
                    if(grid[i][j] == 0 &&!visited[i][j][obs])
                    {
                        q.push({i,j,obs});
                        
                        visited[i][j][obs] = true;
                    }
                    
                    else if(grid[i][j] == 1 && obs>0 && !visited[i][j][obs-1])
                    {
                        q.push({i,j,obs-1});
                        
                        visited[i][j][obs-1] = true;
                    }
                }
            }
        }
        
        steps++;
    }
    
    return -1;
    
}

};