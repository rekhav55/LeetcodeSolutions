// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int targetSum(int arr[], int idx, int target, vector<vector<int>>&dp){
        if(idx==0){
            if(arr[0]==target) return true;
            else return false;
        }
        if(target==0) return true;
        if(target<0) return false;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int take = targetSum(arr,idx-1,target-arr[idx],dp);
        int no_take = targetSum(arr,idx-1,target,dp);
        return dp[idx][target]=take||no_take;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++) sum+=arr[i];
        if(sum%2==1) return false;
        int target = sum/2;
        vector<vector<int>>dp(N+1,vector<int>(target+1,-1));
        return targetSum(arr,N-1,target,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends