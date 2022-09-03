class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        this->k = k, mn = pow(10, n-1);
        for (int i = 1; i < 10; i++) dfs(i);
        return ans;
    }
private:
    int mn = 0, k = 0;
    vector<int> ans;
    
    void dfs(int i) {
        if (i >= mn) {
            ans.push_back(i);
            return;
        }
        int d = i % 10;
        if (d - k >= 0) dfs(10*i + d - k);
        if (k && d + k < 10) dfs(10*i + d + k);
    }
};