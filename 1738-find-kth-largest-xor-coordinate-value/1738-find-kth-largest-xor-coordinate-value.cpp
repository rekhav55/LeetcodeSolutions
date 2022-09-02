class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> pf(m+1,vector<int>(n+1,0));
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                pf[i][j]=pf[i-1][j]^pf[i][j-1]^pf[i-1][j-1]^matrix[i-1][j-1];
                pq.push(pf[i][j]);
                if (pq.size()>k) pq.pop();
            }
        }
        return pq.top();
        
    }
};