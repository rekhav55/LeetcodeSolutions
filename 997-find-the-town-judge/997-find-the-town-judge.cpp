class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>inorder(n+1,0);
        for(auto it:trust){
            inorder[it[0]]--;
            inorder[it[1]]++;
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(inorder[i]==n-1){
                ans = i;
            }
        }
        return ans;
    }
};