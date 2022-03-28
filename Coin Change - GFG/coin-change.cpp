// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  long long int find(int target, int idx, int S[], vector<vector<long long int>>&dp){
      if(idx==0){
          return target%S[0]==0;
      }
      if(dp[idx][target]!=-1) return dp[idx][target];
      long long int no_take = find(target,idx-1,S,dp);
      long long int take = 0;
      if(S[idx]<=target){
          take =find(target-S[idx], idx, S,dp);
      }
      return dp[idx][target]=take+no_take;
  }
    long long int count(int S[], int m, int n) {

        // code here.
        vector<vector<long long int>>dp(m+1,vector<long long int>(n+1,-1));
        for(int i=0;i<=n;i++){
            dp[0][i] = (i%S[0]==0);
        }
        
        for(int idx=1;idx<m;idx++){
            for(int tar=0;tar<=n;tar++){
                long long int no_take = dp[idx-1][tar];
                long long int take = 0;
                if(S[idx]<=tar){
                    take =dp[idx][tar-S[idx]];
                }
                dp[idx][tar]=take+no_take;
            }
        }
        return dp[m-1][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends