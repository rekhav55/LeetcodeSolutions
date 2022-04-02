// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int price[],int idx, int n, vector<vector<int>>&dp){
        if(idx==0){
            return price[idx]*n;
        }
        if(dp[idx][n]!=-1) return dp[idx][n];
        int no = f(price,idx-1,n,dp);
        int take = INT_MIN;
        int rodlength = idx+1;
        if(rodlength<=n){
            take = price[idx] + f(price,idx,n-rodlength,dp);
        }
        return dp[idx][n]=max(no,take);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++){
            dp[0][i] = i*price[0];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int no = dp[i-1][j];
                int take = INT_MIN;
                int rodlength = i+1;
                if(rodlength<=j){
                  take = price[i] + dp[i][j-rodlength];
                }
                dp[i][j]=max(no,take);
            }
        }
        return dp[n-1][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends