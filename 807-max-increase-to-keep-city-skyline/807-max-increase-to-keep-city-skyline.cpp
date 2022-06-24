class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>row(n,0);
        vector<int>col(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                col[j]=max(col[j],grid[i][j]);
                row[i]=max(row[i],grid[i][j]);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int increase = min(row[i],col[j]);
                sum+= abs(grid[i][j]-increase);
            }
        }
        return sum;
    }
};