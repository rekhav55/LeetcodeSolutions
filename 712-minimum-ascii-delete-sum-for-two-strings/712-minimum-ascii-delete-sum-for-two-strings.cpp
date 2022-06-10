class Solution {
public:
    // int f(int i, int j, string &s, string &t,vector<vector<int>>&dp){
    //     if(i==s.size()){
    //         int sum =0;
    //         for(int k=j;k<t.size();k++){
    //             int x = t[k];
    //             sum = sum+ x;
    //         }
    //         return sum;
    //     }
    //     if(j==t.size()){
    //         int sum =0;
    //         for(int k=i;k<s.size();k++){
    //             int x = t[k];
    //             sum = sum+ x;
    //         }
    //         return sum;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int cost1=INT_MAX,cost2=INT_MAX,cost3=INT_MAX;
    //     if(s[i]!=t[j]){
    //         int x = s[i];
    //         int y = t[j];
    //         cost1 = x + f(i+1,j,s,t,dp);
    //         cost2 = y + f(i,j+1,s,t,dp);
    //     }
    //     else{
    //         cost3 = f(i+1,j+1,s,t,dp);
    //     }
    //     return dp[i][j]=min({cost1,cost2,cost3});
    // }
    // int minimumDeleteSum(string s1, string s2) {
    //     int n = s1.size();
    //     int m = s2.size();
    //     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //     return f(0,0,s1,s2,dp);
    // }
    int solve(int i, int j, string &s, string &w,vector<vector<int>>&dp){
        if(i==s.size()){
            int sum=0;
            while(j!=w.size()){
                sum+=(int)w[j++];
            }
            return sum;
        }
        if(j==w.size()){
            int sum=0;
            while(i!=s.size()){
                sum+=(int)s[i++];
            }
            return sum;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans;
        if(s[i]==w[j]){
            ans=solve(i+1,j+1,s,w,dp);
        }
        else{
            int aa=(int)s[i]+solve(i+1,j,s,w,dp);
            int bb=(int)w[j]+solve(i,j+1,s,w,dp);
            ans=min(aa,bb);
        }
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(0,0,s1,s2,dp);
    }
};