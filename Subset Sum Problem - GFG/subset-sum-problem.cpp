// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool find(vector<int>&arr, int sum, int idx,vector<vector<bool>>&dp){
    if(idx==0){
        if(arr[0]==sum) return true;
        return false;
    }
    if(sum==0) return true;
    if(dp[idx][sum]) return dp[idx][sum];
    bool no_take = find(arr,sum,idx-1,dp);
    bool take;
    if(arr[idx]<=sum){
        take = find(arr,sum-arr[idx],idx-1,dp);
    }
    return dp[idx][sum]=take||no_take;
}
    bool isSubsetSum(vector<int>set, int sum){
        // code here 
        int n = set.size();
        bool subset[n+1][sum+1];
        for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }
        return subset[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends