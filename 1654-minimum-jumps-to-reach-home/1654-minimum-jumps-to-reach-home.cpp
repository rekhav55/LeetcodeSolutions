class Solution {
public:
    unordered_set<int> fob;
    int dp[7001][2];
    int solver(int pos, int &home, int &a, int &b, bool left)
    {
        if(pos == home)return 0;
        if(pos < 0 || pos > 7000 || fob.find(pos) != fob.end())return 1e9;
        if(dp[pos][left] != -1) return dp[pos][left];
        
        dp[pos][left] = 1 + solver(pos + a, home, a, b, false);
        if(!left)
        {
            dp[pos][left] = min(dp[pos][left], 1 + solver(pos - b, home, a, b, true));
        }
        return dp[pos][left];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(auto i: forbidden)fob.insert(i);
        memset(dp, -1, sizeof(dp));
        int ans = solver(0, x, a, b, false);
        return (ans >= 1e9)? -1: ans;
    }
};