class Solution {
public:
    bool isPossible(vector<int>& nums) {
         unordered_map<int, int> cnt1, cnt2;
        for (auto& n : nums) cnt1[n]++;
        for (auto& n : nums) {
            if (!cnt1[n]) continue; // this number is running out
            if (cnt2[n - 1]) {      // has subsquence ends with n - 1, put n at the end
                cnt2[n - 1]--;
                cnt2[n]++;
                cnt1[n]--;
            } else if (cnt1[n + 1] && cnt1[n + 2]) { // take n as the head of a new subsquence
                cnt2[n + 2]++;
                cnt1[n]--;
                cnt1[n + 1]--;
                cnt1[n + 2]--;
            } else return false;
        }
        return true;
    }
};