class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
    int rows = nums1.size();
    int cols = nums2.size();
    int result = 0;
    
    vector<vector<int>> dp (rows + 1, vector<int>(cols + 1));
    
    for (int r = rows - 1; r >= 0; r--) {
      for (int c = cols - 1; c >= 0; c--) {
        if (nums1[r] == nums2[c])
          dp[r][c] = 1 + dp[r+1][c+1];
        result = max(result, dp[r][c]);
      }
    }
    
    return result;
  }
};