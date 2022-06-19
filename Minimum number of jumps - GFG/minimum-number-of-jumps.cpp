// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    // long long int find(int idx,int n, int arr[],vector<long long int>&dp){
    //     if(idx==n-1) return 0;
    //     if(idx>=n) return 1e9;
    //     if(arr[idx]==0) return 1e9;
    //     if(dp[idx]!=-1) return dp[idx];
    //     int mini=INT_MAX;
    //     for(int i=1;i<=arr[idx];i++){
    //         int jump = 1 + find(idx+i,n,arr,dp);
    //         mini = min(jump,mini);
    //     }
    //     return dp[idx]=mini;
    // }
    int minJumps(int arr[], int n){
        int end =0,cnt=0, maxreach=0;
        for(int i=0;i<n-1;i++){
            maxreach=max(maxreach,i+arr[i]);
            if(i==end){
                cnt++;
                end=maxreach;
            }
        }
        if(end<n-1) return -1;
        return cnt;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends