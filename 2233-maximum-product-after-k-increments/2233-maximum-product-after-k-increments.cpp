class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        
        while(k--){
            int temp = pq.top();
            pq.pop();
            pq.push(temp+1);
        }
        long long int ans=1;
        int mod=1e9+7;
        while(!pq.empty()){
            ans = (ans*pq.top())%mod;
            pq.pop();
        }
        
        return ans%mod;
    }
};