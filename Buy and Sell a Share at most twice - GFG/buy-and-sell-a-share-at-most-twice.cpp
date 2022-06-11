// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
int f(int idx, int buy, int k, vector<int>&price,vector<vector<vector<int>>>&dp){
    if(idx==price.size() || k==0) return 0;
    if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
    int take=INT_MIN,no_take=INT_MIN;
    if(buy==0){
        take = -price[idx]+f(idx+1,1,k,price,dp);
        no_take = f(idx+1,buy,k,price,dp);
    }
    else if(buy==1){
        take = price[idx]+f(idx+1,0,k-1,price,dp);
        no_take = f(idx+1,buy,k,price,dp);
    }
    
    return dp[idx][buy][k]=max(take,no_take);
}
int maxProfit(vector<int>&price){
    //Write your code here..
    vector<vector<vector<int>>>dp(price.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
    return f(0,0,2,price,dp);
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}
  // } Driver Code Ends