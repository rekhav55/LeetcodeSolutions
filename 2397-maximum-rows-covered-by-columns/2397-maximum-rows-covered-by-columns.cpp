class Solution {
public:
    vector<int> col;
    int ans = 0;
    int check(vector<int>& col, vector<vector<int>>& mat){
        int cnt = 0;
        for(int i=0; i < mat.size(); i++){
            bool flag = true;
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j]==1 && col[j]!=1) flag = false;
            }
            if(flag) cnt++;
        }
        return cnt;
    }
    
    void solve(vector<vector<int>>& mat, int cols, int i){
        if(cols==0){
            int rows = check(col, mat);
            ans = max(ans, rows);
            return;
        }
        if(i == mat[0].size()) return;
        col[i] = 1;
        solve(mat, cols-1, i+1);
        col[i] = 0;
        solve(mat, cols, i+1);
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        col.resize(mat[0].size());
        solve(mat, cols, 0);
        return ans;
    }
};