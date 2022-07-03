class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int, int> > stk;
        int ans = 0;
        //first: number itself
        //second: the step in which it will get deleted
        //first element will never get deleted so its second param is 0
        stk.push({nums[0], 0});
        for (int i = 1; i < n; i++) {
            int mx = 0;
            while (!stk.empty() && stk.top().first <= nums[i]) {
                mx = max(mx, stk.top().second);
                stk.pop();
            }
            if (stk.empty()) {
                stk.push({nums[i], 0});
                continue;
            } else {
                stk.push({nums[i], mx + 1});
            }
            ans = max(ans, mx + 1);
        }
        return ans;
    }
};
