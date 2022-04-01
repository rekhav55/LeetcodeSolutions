// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int find(int r, int c, vector<vector<int>>&mat, int n, int m, vector<vector<int>>&visited,vector<vector<int>>&dp){
        if(r<0 || c<0 || r>=n || c>=m || visited[r][c]==1) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        visited[r][c]=1;
        int upper = find(r-1,c+1,mat,n,m,visited,dp);
        int right = find(r,c+1,mat,n,m,visited,dp);
        int lower = find(r+1,c+1,mat,n,m,visited,dp);
        visited[r][c]=0;
        return dp[r][c]=mat[r][c] + max({upper,right,lower});
        
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int ans =0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            vector<vector<int>>visited(n,vector<int>(m,0));
            int gold = find(i,0,M,n,m,visited,dp);
            ans = max(ans,gold);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends