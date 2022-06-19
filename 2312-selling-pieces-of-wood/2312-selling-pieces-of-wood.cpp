typedef long long ll;

class Solution {
    unordered_map<ll, ll> piece;
    vector<vector<ll>> t;

    ll solve(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        if (t[m][n] != -1) return t[m][n];

        ll res = 0;

        auto it = piece.find(m * 1000001ll + n);
        if (it != piece.end()) res = it->second;

        for (int i = 1; i < m; i++) {
            res = max(res, solve(i, n) + solve(m - i, n));
        }
        for (int i = 1; i < n; i++) {
            res = max(res, solve(m, i) + solve(m, n - i));
        }

        t[m][n] = res;
        return t[m][n];
    }

public:
    long long sellingWood(int m, int n, vector<vector<int>> &prices) {
        for (auto &v : prices) {
            piece[v[0] * 1000001ll + v[1]] = v[2];
        }
        t.resize(m + 1, vector<ll>(n + 1, -1));
        return solve(m, n);
    }
};