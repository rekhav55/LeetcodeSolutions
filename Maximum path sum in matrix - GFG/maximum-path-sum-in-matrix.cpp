// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int r, int c, vector<vector<int>>&mat, vector<vector<int>>&vis,vector<vector<int>>&dp){
        if(r<0 || c<0 || r>=mat.size() || c>=mat[0].size() || vis[r][c]==1){
            return 0;
        }
        if(r==mat.size()-1) return mat[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        vis[r][c]=1;
        int ri = mat[r][c]+solve(r+1,c,mat,vis,dp);
        int u = mat[r][c]+solve(r+1,c-1,mat,vis,dp);
        int d = mat[r][c]+solve(r+1,c+1,mat,vis,dp);
        vis[r][c]=0;
        return dp[r][c]=max({ri,u,d});
        
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int ans =0, res=0;
        vector<vector<int>>dp(Matrix.size()+1, vector<int>(Matrix[0].size()+1, -1));
        for(int col = 0; col<Matrix[0].size(); col++){
            vector<vector<int>>visited(Matrix.size(), vector<int>(Matrix[0].size(),0));
            int ans = solve(0,col,Matrix,visited,dp);
            res = max(res,ans);
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends