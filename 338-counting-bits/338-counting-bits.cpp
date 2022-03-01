class Solution {
public:
    int countbits(int x){
        int count=0;
        while(x){
            x&=(x-1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>res(n+1);
        for(int i=0;i<=n;i++){
            res[i]=countbits(i);
        }
        return res;
    }
};