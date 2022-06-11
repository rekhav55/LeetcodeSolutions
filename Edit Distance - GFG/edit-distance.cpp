// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int f(int i, int j, string &s, string &t, vector<vector<int>>&dp){
      if(i==s.size() && j==t.size()) return 0;
      if(i==s.size() && j<t.size()) return t.size()-j;
      if(j==t.size() && i<s.size()) return s.size()-i;
      if(dp[i][j]!=-1) return dp[i][j];
      if(s[i]==t[j]){
          return dp[i][j] = f(i+1,j+1,s,t,dp);
      }
      else{
          return dp[i][j]= min({1+f(i,j+1,s,t,dp),1+f(i+1,j+1,s,t,dp),1+f(i+1,j,s,t,dp)});
      }
  }
    int editDistance(string s, string t) {
        // Code here
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        return f(0,0,s,t,dp);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends