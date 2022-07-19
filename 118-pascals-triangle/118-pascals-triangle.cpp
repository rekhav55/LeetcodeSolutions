class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        vector<int>temp;
        if(numRows==1){
            temp.push_back(1);
            res.push_back(temp);
            return res;
        }
        else if(numRows==2){
            res.push_back({1});
            res.push_back({1,1});
            return res;
        }
        else{
            res.push_back({1});
            res.push_back({1,1});
            for(int i=2;i<numRows;i++){
                for(int j=0;j<=i;j++){
                    if(j-1>=0 && j+1<=i){
                        temp.push_back(res[i-1][j]+res[i-1][j-1]);
                    }
                    else{
                        temp.push_back(1);
                    }
                }
                res.push_back(temp);
                temp.clear();
            }
        }
        return res;
    }
};