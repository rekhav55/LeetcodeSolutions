class Solution {
public:
    vector<vector<int>>res={};
    void solve(vector<int>&candidates, int target, vector<int>temp, int index){
        
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(target<0) return;
        if(index==candidates.size()) return;
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            solve(candidates,target-candidates[index],temp,index);
            temp.pop_back();
        }
        solve(candidates,target,temp,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp={};
        solve(candidates,target,temp,0);
        return res;
    }
};