class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> pref(n,0);
        vector<int> sum;
        
        int tempSum = 0;
        for(int i=0; i<n; i++){
            tempSum += nums[i];
            pref[i] = tempSum;
            sum.push_back(pref[i]);
        }
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                sum.push_back(pref[j]-pref[i]);
            }
        }
        
        sort(sum.begin(), sum.end());
        
        int N = sum.size();
        
        tempSum = 0;
        vector<int> prefsum(N);
        for(int i=0; i<N; i++){
            tempSum = (tempSum + sum[i]) % 1000000007;
            prefsum[i] = tempSum;    
        }
        
        left-=1;
        right-=1;
        
        return prefsum[right] - (left-1>=0 ? prefsum[left-1] : 0);
    
        // int ans=0;
        // vector<int>res;
        // for(int i=0;i<nums.size();i++){
        //     int sum = nums[i];
        //     res.push_back(sum);
        //     for(int j=i+1;j<nums.size();j++){
        //         sum+=nums[j];
        //         res.push_back(sum);
        //     }
        // }
        // sort(res.begin(),res.end());
        // for(int i=left-1;i<=right-1;i++){
        //     ans+=res[i];
        //     ans= ans%(1000000000+7);
        // }
        // return ans;
    }
};