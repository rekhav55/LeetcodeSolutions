class Solution {
public:
    int f(int i,int j, string &s, string &t,vector<vector<int>>&dp){
        if(i==s.size() && j==t.size()){
            return 0;
        }
        if(i==s.size() && j<t.size()){
            return t.size()-j;
        }
        if(j==t.size() && i<s.size()){
            return s.size()-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int val=0;
        if(s[i]==t[j]){
            val+=f(i+1,j+1,s,t,dp);
        }
        else{
            val+= min(1+f(i,j+1,s,t,dp),1+f(i+1,j,s,t,dp));
        }
        
        return dp[i][j]=val;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return f(0,0,word1,word2,dp);
    }
};