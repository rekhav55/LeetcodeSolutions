class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int len = security.size();
        vector<int> non_increasing(len,0);
        vector<int> non_decreasing(len,0);
        for (int i = 1; i < len; ++i) {
            if (security[i - 1] >= security[i]) {
                non_increasing[i] = non_increasing[i - 1] + 1;
            }
        }
        
        for (int i = len - 2; i >= 0; --i) {
            if (security[i] <= security[i + 1]) {
                non_decreasing[i] = non_decreasing[i + 1] + 1;
            }
        }
        
        vector<int> res;
        for (int i = 0; i < len; ++i) {
            if (non_increasing[i] >= time and non_decreasing[i] >= time)
                res.push_back(i);
        }
        return res;
    }
    
};