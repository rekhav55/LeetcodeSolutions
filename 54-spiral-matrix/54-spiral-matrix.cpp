class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int minRow =0,minCol=0, maxRow=matrix.size()-1,maxCol=matrix[0].size()-1;
        int total = matrix.size()*matrix[0].size();
        int cnt=0;
        vector<int>res;
        while(cnt<total){
            //top wall
            if(cnt<total){
            for(int i=minCol,j=minRow;i<=maxCol;i++){
                res.push_back(matrix[j][i]);
                cnt++;
            }
            }
            minRow++;
            //right wall
            if(cnt<total){
                for(int i=minRow,j=maxCol;i<=maxRow;i++){
                res.push_back(matrix[i][j]);
                cnt++;
            }
            }
            
            maxCol--;
            //bottom wall
            if(cnt<total){for(int i=maxCol,j=maxRow;i>=minCol;i--){
                res.push_back(matrix[j][i]);
                cnt++;
            }}
            
            maxRow--;
            //left wall
            if(cnt<total){
                for(int i=maxRow,j=minCol;i>=minRow;i--){
                res.push_back(matrix[i][j]);
                cnt++;
            }
            }
            
            minCol++;
        }
        return res;
    }
};