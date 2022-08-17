class Solution {
public:
    int nextGreaterElement(int n) {
        int temp = n;
        vector<int>res;
        while(temp){
            int rem = temp%10;
            temp/=10;
            res.push_back(rem);
        }
        reverse(res.begin(),res.end());
        
        int t = res.size();
        int i=t-2;
        int l = t-1;
        for(i=t-2;i>=0;i--){
            if(res[i]<res[i+1]){
                break;
            }
        }
        if(i<0) return -1;
        for(l=t-1;l>i;l--){
            if(res[l]>res[i]) break;
        }
        swap(res[l],res[i]);
        reverse(res.begin()+i+1,res.end());
        long long int ans=0;
        for(int k=0;k<t;k++){
            ans = ans*10+res[k];
            if(ans>INT_MAX) return -1;
        }
        return ans;
    }
};