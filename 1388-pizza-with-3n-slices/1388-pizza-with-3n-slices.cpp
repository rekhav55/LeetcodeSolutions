class Solution {
public:
    int f(vector<int>& arr,int ind,int n,vector<vector<int>> &dp){
        if(ind >= arr.size() || n== 0) return 0;
        if(dp[ind][n] !=-1) return dp[ind][n];
        
        int not_take = f(arr,ind+1,n,dp); // When not taking a slice we just move to next index.
        int take = arr[ind] + f(arr,ind+2,n-1,dp); // When take a slice we add the slice value and decrement the available slices by 1 and move to next index.
        
        return dp[ind][n] = max({take,not_take});
        
    }
    int maxSizeSlices(vector<int>& slices) {
        vector<int> arr1(slices.begin(),slices.end()-1); // array when not considering the last value i.e for clockwise.
        vector<int> arr2(slices.begin()+1,slices.end()); // array when not considering the first value i.e for anti-clockwise.
        int n = slices.size()/3;
        vector<vector<int>> dp1(501,vector<int>(n+1,-1)); // When Bob participates  then your max
        vector<vector<int>> dp2(501,vector<int>(n+1,-1)); // When Alice participates  then your max
        return max({f(arr1,0,n,dp1),f(arr2,0,n,dp2)}); // your max between those two.
    }
};