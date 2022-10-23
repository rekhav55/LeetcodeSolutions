class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>dup(n+1,0);
        int ans =0, miss=0;
        for(int i=0;i<n;i++){
            dup[nums[i]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(dup[i]==0){
                miss=i;
            }
            if(dup[i]==2){
                ans=i;
            }
        }
        
        vector<int>temp;
        temp.push_back(ans);
        temp.push_back(miss);
        return temp;
    }
};