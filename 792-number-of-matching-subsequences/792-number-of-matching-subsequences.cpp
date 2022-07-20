class Solution {
public:
    bool isSubsequence(string s,string t)//whether t is subsequence of s
    {
        int k=0;
        for(int i=0;i<s.length();i++)
        {
            if(t[k]==s[i])k++;
            if(k==t.length())return true;
        }
        return false;
    }
   
    
    int numMatchingSubseq(string s, vector<string>& words)
    {
         unordered_map<string,int>ump;//string ,frequency
        for(int i=0;i<words.size();i++)
        {
            ump[words[i]]++;
        }
        int ans=0;
        for(auto x:ump)
        {
           if(isSubsequence( s,x.first))ans=ans+x.second;
        }

        return ans;
    }
};