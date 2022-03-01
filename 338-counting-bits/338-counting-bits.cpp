class Solution {
public:
    // int countbits(int x){
    //     int count=0;
    //     while(x){
    //         x&=(x-1);
    //         count++;
    //     }
    //     return count;
    // }
    vector<int> countBits(int n) {
        vector<int>res(n+1);
        res[0]=0;
        for(int i=1;i<=n;i++){
            res[i]=res[i>>1]+i%2;
        }
        return res;
    }
};