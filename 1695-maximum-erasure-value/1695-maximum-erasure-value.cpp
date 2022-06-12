class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> m;
            int ans = 0;
            int sum = 0;
            int i = 0;
            int j = 0;
            while (j < nums.size())
            {
                sum += nums[j];
                m[nums[j]]++;
                if (m.size() == j - i + 1)
                {
                    ans = max(sum, ans);
                }
                else
                {
                    while (m.size() < j - i + 1)
                    {
                        m[nums[i]]--;
                        sum -= nums[i];
                        if (m[nums[i]] == 0) m.erase(nums[i]);
                        i++;
                    }
                    ans = max(ans, sum);
                }
                j++;
            }
            return ans;
    }
};