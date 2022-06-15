class Solution {
    static bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
public:
    bool possible(string s1, string s2){
        if(s1.size()!=s2.size()+1) return false;
        int f =0,s=0;
        while(f<s1.size()){
            if(s1[f]==s2[s]){
                f++;
                s++;
            }
            else{
                f++;
            }
        }
        if(f==s1.size() && s==s2.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int maxi=1;
        vector<int>dp(words.size(),1);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(possible(words[i],words[j]) && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                }
            }
            
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};