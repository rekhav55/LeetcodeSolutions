class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return nums.size();
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans = INT_MIN,cnt=1;
        for(auto it:mp){
            if(mp.count(it.first+1)>0){
                cnt++;
            }
            else{
                cnt=1;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};