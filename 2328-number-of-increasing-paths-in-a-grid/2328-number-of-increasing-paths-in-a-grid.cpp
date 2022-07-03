class Solution {
    public:
   int mod = 1e9 + 7;
    int ans;
    int dp[1001][1001];
    int n,m;
    
    bool valid(int i,int j){
        return (i>=0 and j>=0 and i<n and j<m);
    }
    
    int dirx[4]={0,1,-1,0};
    int diry[4]={1,0,0,-1};
    
    void dfs(int i,int j,vector<vector<int>>& grid){
        
        if(!valid(i,j))
            return;        
        if(dp[i][j]!=-1){
            return;
        }        
        dp[i][j] = 1;
		
        for(int ind=0;ind<4;++ind){
            int newi=i+dirx[ind],newj=j+diry[ind];
            if(valid(newi,newj) and grid[newi][newj]>grid[i][j]){
                dfs(newi,newj,grid);
                dp[i][j] += dp[newi][newj];
                dp[i][j] %= mod;
            }
        }
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        
        for(int i=0;i<1000;++i){
            for(int j=0;j<1000;++j){
                dp[i][j] = -1;
            }
        }
        
        ans = 0;
        n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int len = 1;
                dfs(i,j,grid);
                ans = (ans%mod + dp[i][j]%mod)%mod;
            }
        }
        
        return ans%mod;
    }
};