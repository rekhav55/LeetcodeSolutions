class Solution {
public:
    vector<vector<int>>res={};
    void solve(vector<int>&candidates, int target, vector<int>temp, int index){
        
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int i = index; i<candidates.size();i++){
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],temp,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp={};
        solve(candidates,target,temp,0);
        return res;
    }
};