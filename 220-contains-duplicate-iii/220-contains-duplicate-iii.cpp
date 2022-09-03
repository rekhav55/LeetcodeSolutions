class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long long int,long long int>>temp(nums.size());
        for(int i=0;i<nums.size();i++){
            temp[i].first = nums[i];
            temp[i].second=i;
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size()-1;i++){
            for(int j=i+1;j<temp.size();j++){
                if(abs(temp[i].first + t >= temp[j].first))
            {  
                if(abs(temp[i].second - temp[j].second) <= k)
                    return true;
            }
            else
                break;
            }
        }
        return false;
    }
};