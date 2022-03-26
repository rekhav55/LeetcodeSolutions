class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
            if(mp[it]>nums.size()/2) return it;
        }
        return -1;
    }
};