class Solution {
public:
    int lps(int i, int j, string &s, string &t,vector<vector<int>>&dp){
        if(i>=s.size() || j>=t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=1+lps(i+1,j+1,s,t,dp);
        }
        else{
            return dp[i][j]=max(lps(i,j+1,s,t,dp),lps(i+1,j,s,t,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string t = "";
        for(int i=s.size()-1;i>=0;i--){
            t+=s[i];
        }
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        for(int i=0;i<=s.size();i++){
            dp[i][s.size()]=0;
            dp[s.size()][i]=0;
        }
        
        for(int i=s.size()-1;i>=0;i--){
            for(int j=s.size()-1;j>=0;j--){
                if(s[i]==t[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};