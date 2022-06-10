class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int ans = 0;
        for(int i=0,j=0;i<s.length();i++){
            mp[s[i]]++;
            if(mp.size()==(i-j+1)){
                if(ans<mp.size()) ans = mp.size();
            }
            else if(mp.size()<(i-j+1)){
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};