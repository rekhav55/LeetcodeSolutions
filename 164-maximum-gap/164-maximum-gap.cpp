class Solution {
public:
    int maximumGap(vector<int>& nums) {
        multiset<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        
        int res = -1;
        int ans=0;
        for(auto it:st){
            if(res==-1){
                res=it;
            }
            else{
                ans = max(ans,abs(it-res));
                res=it;
            }
        }
        return ans;
    }
};