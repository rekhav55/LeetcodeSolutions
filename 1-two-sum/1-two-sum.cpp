class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int f;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            f = target - nums[i];
            if(mp.find(f)!=mp.end()){
                auto j = mp.find(f);
                v.push_back(j->second);
                v.push_back(i);
                break;
            }
            mp[nums[i]]=i;
            
        }
        return v;
    }
};