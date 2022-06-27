class Solution {
public:
    bool f(int i, int j, string&s, string &p,vector<vector<int>>&dp){
        if(i>=s.size() && j>=p.size()) return true;
        if(j>=p.size()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool match = i<s.size() and (s[i]==p[j] || p[j]=='.');
        if(j<p.size()-1 && p[j+1]=='*'){
            return dp[i][j]=f(i,j+2,s,p,dp) || (match && f(i+1,j,s,p,dp));
        }
        if(match){
            return dp[i][j]=f(i+1,j+1,s,p,dp);
        }
        
        return false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return f(0,0,s,p,dp);
    }
};
