// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int score(int arr[], int i, int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int x = arr[i] + min(score(arr,i+2,j,dp),score(arr,i+1,j-1,dp));
        int y = arr[j] + min(score(arr,i+1,j-1,dp),score(arr,i,j-2,dp));
        return dp[i][j]=max(x,y);
    }
    bool is1winner(int N,int arr[]) {
        
        // code here
        int sum=0;
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        for(int i=0;i<N;i++) sum+=arr[i];
        int ans = score(arr,0,N-1,dp);
        if(ans>(sum-ans)) return true;
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.is1winner(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends