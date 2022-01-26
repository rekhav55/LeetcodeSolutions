class Solution {
public:
    
    void solve(vector<int>&candidates, int target, vector<int>temp, vector<vector<int>>&res,int index){
        
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(target<0) return;
        if(index==candidates.size()) return;
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            solve(candidates,target-candidates[index],temp,res,index);
            temp.pop_back();
        }
        solve(candidates,target,temp,res,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>res;
        solve(candidates,target,temp,res,0);
        return res;
    }
};