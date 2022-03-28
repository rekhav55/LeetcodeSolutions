// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // int knap(int idx, int w,int wt[], int val[], vector<vector<int>>&dp ){
    //     if(idx==0){
    //         if(wt[0]<=w){
    //             return val[0];
    //         }
    //         return 0;
    //     }
    //     if(dp[idx][w]!=-1) return dp[idx][w];
    //     int not_take = 0 + knap(idx-1,w,wt,val,dp);
    //     int take=INT_MIN;
    //     if(wt[idx]<=w){
    //         take = val[idx]+knap(idx-1,w-wt[idx],wt,val,dp);
    //     }
    //     return dp[idx][w]= max(not_take,take);
    // }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(w+1,0));
       for(int i=wt[0];i<=w;i++) dp[0][i]=val[0];
       for(int idx=1;idx<n;idx++){
           for(int W=0;W<=w;W++){
               int not_take = 0 + dp[idx-1][W];
               int take=INT_MIN;
               if(wt[idx]<=W){
                  take = val[idx]+dp[idx-1][W-wt[idx]];
               }
               dp[idx][W]= max(not_take,take);
            }
        }
       return dp[n-1][w];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends