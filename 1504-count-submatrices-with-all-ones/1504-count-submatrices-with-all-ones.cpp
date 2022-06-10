class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
         for(int i=0;i<mat.size();i++){
             for(int j=mat[0].size()-2;j>=0;j--){
                 if(mat[i][j]==1){
                     mat[i][j]+=mat[i][j+1];
                 }
             }
         }
        int cnt=0;
         for(int i=0;i<mat.size();i++){
             for(int j=0;j<mat[0].size();j++){
                 int min_width = mat[i][j];
                 for(int d = i;d<mat.size();d++){
                     if(mat[d][j]==0) break;
                     min_width = min(min_width,mat[d][j]);
                     cnt+=min_width;
                 }
             }
         }
        return cnt;
         
    }
};