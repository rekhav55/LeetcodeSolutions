class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int ans=0;
      int n=nums.size(),maxi=INT_MIN;
      for(int i=0;i<n;i++){
          maxi=max(maxi,nums[i]);
          if(i==maxi) ans++;
      }
      return ans;
    }
};