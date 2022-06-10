class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
    vector<int> dp(n, 1), hash(n);
    int maxEle = 1, target = 0;
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < n; i++)
    {
        hash[i] = i;
        for(int j = i - 1; j >= 0; j--)
        {
            if(arr[i] % arr[j] == 0 and dp[i] < 1 + dp[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
                hash[i] = j;
            }
        }
        maxEle = max(maxEle, dp[i]);
        if(maxEle == dp[i]){
            target = i;
        }
    }
    vector<int> v;
    v.push_back(arr[target]);

    while(hash[target] != target)
    {
        v.push_back(arr[hash[target]]);
        target = hash[target];
    }
    return v;
    }
};