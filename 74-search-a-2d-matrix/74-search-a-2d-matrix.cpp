class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int j = matrix[0].size()-1;
        for(int i=0;i<matrix.size();i++){
            if(target>=matrix[i][0] && target<=matrix[i][j]){
                int left=0,right=j;
                while(left<=right){
                    int mid = (left+right)/2;
                    if(matrix[i][mid]==target) return true;
                    else if(matrix[i][mid]<target){
                        left=mid+1;
                    }
                    else{
                        right=mid-1;
                    }
                }
            }
        }
        return false;
    }
};