class Solution {
public:
    bool isPossible(vector<int>wt,int mid,int days){
        int sum =0, d =1;
        for(int i=0;i<wt.size();i++){
            if(wt[i]>mid) return false;
            sum+=wt[i];
            if(sum>mid){
                d++;
                sum=wt[i];
            }
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maximum=0, sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            maximum = max(maximum,weights[i]);
        }
        
        if(days==weights.size()) return maximum;
        int low = maximum;
        int high = sum;
        int ans =0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(weights,mid,days)==true){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};