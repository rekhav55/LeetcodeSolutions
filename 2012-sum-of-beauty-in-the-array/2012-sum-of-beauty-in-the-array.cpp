class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(), maxSoFar = nums[0], minSoFar = nums[n-1];
        vector<int> beauty(n, 0);
        
        for(int i=1; i<n-1; i++)
        {
            if(nums[i] > maxSoFar) beauty[i] = 2;
            else if(nums[i] > nums[i-1]) beauty[i] = 1;
            else beauty[i] = 0;
            maxSoFar = max(maxSoFar, nums[i]);
        }
        
        for(int i=n-2; i>0; i--)
        {
            if(beauty[i] == 2 and nums[i] < minSoFar) beauty[i] = 2;
            else if((beauty[i] == 2 or beauty[i] == 1) and nums[i] < nums[i+1]) beauty[i] = 1;
            else beauty[i] = 0;
            minSoFar = min(minSoFar, nums[i]);
        }
        
        return accumulate(beauty.begin(), beauty.end(), 0);
    }
};