class Solution {
public:
    int minimumSum(int num) {
        vector<int>temp;
        int t = num;
        while(t!=0){
            int rem = t%10;
            temp.push_back(rem);
            t/=10;
        }
        
        sort(temp.begin(),temp.end());
        
        int first = temp[0]*10+ temp[3];
        int second = temp[1]*10 + temp[2];
        
        return first+second;
    }
};