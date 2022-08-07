class Solution {
public:
    // int f(int r, int c, vector<vector<int>>&vis,vector<vector<int>>&grid,int dr, int dc){
    //     if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || vis[r][c]==1) return 1e9;
    //     if(r==dr && c==dc) return 0;
    //     // if(dp[r][c]!=-1) return dp[r][c];
    //     vis[r][c]=1;
    //     int up=0,down=0,left=0,right=0;
    //     if(grid[r][c]==1){
    //         up=1+f(r-1,c,vis,grid,dr,dc);
    //         down=1+f(r+1,c,vis,grid,dr,dc);
    //         left=1+f(r,c-1,vis,grid,dr,dc);
    //         right=1+f(r,c+1,vis,grid,dr,dc);
    //     }
    //     else{
    //         up=f(r-1,c,vis,grid,dr,dc);
    //         down=f(r+1,c,vis,grid,dr,dc);
    //         left=f(r,c-1,vis,grid,dr,dc);
    //         right=f(r,c+1,vis,grid,dr,dc);
    //     }
    //     vis[r][c]=0;
    //     return min({up,left,right,down});
    // }
    int minimumObstacles(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        
        priority_queue < pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>      > pq;
        int dist[m][n];
        for(int i=0;i<m;i++) 
            for(int j=0;j<n;j++)
                dist[i][j] = INT_MAX;
        
        dist[0][0] = grid[0][0];
        
        int dir[5] = {0,1,0,-1,0};
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()) {
            auto cur = pq.top();
            int cost = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;
            vis[x][y] = 1;
            pq.pop();
            for(int i=0;i<4;i++) {
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                if(nx<0 || ny<0 || nx>=m || ny>=n || vis[nx][ny] ) continue;
                if(dist[nx][ny] > grid[nx][ny] + dist[x][y]) {
                    dist[nx][ny] = grid[nx][ny] + dist[x][y];
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
        
        return dist[m-1][n-1];
    
    }
};