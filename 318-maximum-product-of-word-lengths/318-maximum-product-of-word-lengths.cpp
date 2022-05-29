class Solution {
public:
    int maxProduct(vector<string>& words) {
        // int maxi=0;
        // for(int i=0;i<words.size();i++){
        //     vector<int>freq(26,0);
        //     for(int k=0;k<words[i].size();k++){
        //         freq[words[i][k]-'a']++;
        //     }
        //     for(int j=i+1;j<words.size();j++){
        //         int flag=0;
        //         for(int k=0;k<words[j].size();k++){
        //             if(freq[words[j][k]-'a']>0){
        //                 flag=1;
        //                 break;
        //             }
        //         }
        //         if(flag==0){
        //             int n = words[i].size();
        //             int m = words[j].size();
        //             maxi = max(maxi, n*m);
        //         }
        //     }
        // }
        // return maxi;
        int n=words.size(),mx=0;
        vector<long> nums;
        for(string s:words){
            bitset<26> mask;
            for(char i:s)
                mask[i-'a']=1;
            nums.push_back(mask.to_ulong());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((nums[i]&nums[j])==0)
                    mx=max(mx,(int)words[i].size()*(int)words[j].size());
            }
        }
        return mx;
    }
};