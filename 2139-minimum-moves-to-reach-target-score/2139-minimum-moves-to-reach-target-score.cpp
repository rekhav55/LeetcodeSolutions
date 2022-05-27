class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        while(target!=1 && maxDoubles>0){
            if(target%2==0){
                ans++;
                target/=2;
                maxDoubles--;
            }
            else{
                target--;
                ans++;
            }
        }
        
        ans+=target-1;
        return ans;
    }
};