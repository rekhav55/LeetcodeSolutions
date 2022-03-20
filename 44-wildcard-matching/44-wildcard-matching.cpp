class Solution {
public:
//     bool f(int i, int j, string &p, string &s, vector<vector<bool>>&dp){
        
//         if(i==0 && j==0) return dp[i][j]=true;
//         if(i==0 && j>0) return dp[i][j]=false;
//         if(j==0 && i>0){
//             for(int k=1;k<=i;k++){
//                 if(p[k-1]!='*') return dp[i][j]=false;
//             }
//             return dp[i][j]=true;
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(p[i-1]==s[j-1] || p[i-1]=='?') return dp[i][j]=f(i-1,j-1,p,s,dp);
//         if(p[i-1]=='*') return dp[i][j]= (f(i-1,j,p,s,dp) || f(i,j-1,p,s,dp));
//         return dp[i][j]=false;
//     }
    bool isMatch(string s, string t) {
       int m = s.size();
    int n = t.size();
    vector<vector<bool>> dp(n+1, vector<bool> (m+1,0));

    // base case - 1
    dp[0][0] = 1;
    // base case - 2
    for(int j=1;j<=m;j++) dp[0][j] = false;
    // base case - 3
    for(int i=1;i<=n;i++){
        int flag = true;
        for(int k=1;k<=i;k++){
            if(t[k-1] != '*'){
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }
        for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //if they matched
            if(t[i-1] == s[j-1] || t[i-1]=='?') dp[i][j] = dp[i-1][j-1];

            // if They DO NOT match
            else if(t[i-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }

            else dp[i][j] = false;
        }
    }
    return dp[n][m];
    }
};