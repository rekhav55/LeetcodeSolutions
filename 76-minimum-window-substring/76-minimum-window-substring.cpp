class Solution {
public:
      string minWindow(string s, string p) {
        if(s.size()<p.size())
            return "";
        int ctr=0;
        unordered_map<char,int>mp2;
        for(int i=0;i<p.size();i++)
        {
            mp2[p[i]]++;
            ctr++;
        }
        int left=0,right=0,curr_cnt=0,l=INT_MAX;
        string ans="";
        unordered_map<char,int>mp1;
        for(int right=0;right<s.size();right++)
        {
            mp1[s[right]]++;
            if(mp1[s[right]]<=mp2[s[right]])
                {
                    curr_cnt++;
                }
            while(curr_cnt==ctr)
            {
                if(l>right-left+1)
                {
                    ans=s.substr(left,right-left+1);
                    l=ans.size();
                }
                mp1[s[left]]--;
                if(mp1[s[left]]<mp2[s[left]])
                    curr_cnt--;
                left++;
            }
        }
        return ans;
    }
};