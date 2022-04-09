// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int N, int A[]) {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(2*k+1,-1));
        for(int i=0;i<=2*k;i++){
            dp[N][i]=0;
        }
        for(int i=0;i<=N;i++){
            dp[i][2*k]=0;
        }
        
        for(int idx=N-1;idx>=0;idx--){
            for(int tra=2*k-1;tra>=0;tra--){
                int profit = INT_MIN;
                if(tra%2==0){
                    profit = max(-A[idx]+dp[idx+1][tra+1],dp[idx+1][tra]);
                }
                else{
                    profit = max(A[idx]+dp[idx+1][tra+1],dp[idx+1][tra]);
                }
                dp[idx][tra]=profit;
            }
        }
        return dp[0][0];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends