class Solution {
public:
    vector<vector<int>>res;
    void f(int idx,int k,vector<int>ans,int &n){
        if(ans.size()==k){
            res.push_back(ans);
            return;
        }
        for(int i=idx;i<=n;i++){
            ans.push_back(i);
            f(i+1,k,ans,n);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if(k>n) return res;
        vector<int>ans;
        f(1,k,ans,n);
        return res;
    }
};