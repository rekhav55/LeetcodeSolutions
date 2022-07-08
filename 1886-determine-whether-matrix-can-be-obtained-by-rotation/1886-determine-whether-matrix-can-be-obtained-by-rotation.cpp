class Solution {
public:
    void transpose(vector<vector<int>>&mat){
        for(int i=0;i<mat.size();i++){
            for(int j=i+1;j<mat[0].size();j++){
                int temp = mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=temp;
            }
        }
    }
    
    void reverse(vector<vector<int>>&mat){
        int n = mat[0].size();
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<n/2;j++){
                int temp = mat[i][j];
                mat[i][j]=mat[i][n-j-1];
                mat[i][n-j-1]=temp;
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target) return true;
        int i=1;
        while(i<=3){
            transpose(mat);
            reverse(mat);
            if(mat==target) return true;
            i++;
        }
        return false;
    }
};