class Solution {
public:
    bool f(int i, int j, int k, string &s1, string &s2, string &s3,vector<vector<int>>&dp){
        if(k>=s3.size() && i>=s1.size() && j>=s2.size()) return true;
        if(k>=s3.size() &&(i<s1.size() || j<s2.size())) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s3[k]==s1[i] && s3[k]!=s2[j]){
            return dp[i][j]=f(i+1,j,k+1,s1,s2,s3,dp);
        }
        else if(s3[k]==s2[j] && s3[k]!=s1[i]){
            return dp[i][j]=f(i,j+1,k+1,s1,s2,s3,dp);
        }
        else if(s3[k]==s1[i] && s3[k]==s2[j] && j<s2.size() && i<s1.size()){
            return dp[i][j]=f(i,j+1,k+1,s1,s2,s3,dp) || f(i+1,j,k+1,s1,s2,s3,dp);
        }
        return dp[i][j]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return f(0,0,0,s1,s2,s3,dp);
    }
};