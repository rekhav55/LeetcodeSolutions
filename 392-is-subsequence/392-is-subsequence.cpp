class Solution {
public:
   int lcs(int i, int j,string m, string n,vector<vector<int>>&dp){
       if(i==m.size()) return 0;
       if(j==n.size()) return 0;
       if(dp[i][j]!=-1) return dp[i][j];
       if(m[i]==n[j]){
           return dp[i][j]=1+lcs(i+1,j+1,m,n,dp);
       }
       else{
           return dp[i][j]=max(lcs(i+1,j,m,n,dp),lcs(i,j+1,m,n,dp));
       }
        // int x = m.length();
        // int y = n.length();
        // int dp[x+1][y+1];
        // for(int i=0;i<=x;i++){
        //     dp[i][0]=0;
        // }
        // for(int i=0;i<=y;i++){
        //     dp[0][i]=0;
        // }
        // for(int i=1;i<=x;i++){
        //     for(int j=1;j<=y;j++){
        //         if(m[i-1]==n[j-1]) dp[i][j]=1+dp[i-1][j-1];
        //         else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //     }
        // }
        // return dp[x][y];
    }
    bool isSubsequence(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        int len = lcs(0,0,s,t,dp);
        int rem = s.length()-len;
        if(rem == 0) return true;
        return false;
    }
};