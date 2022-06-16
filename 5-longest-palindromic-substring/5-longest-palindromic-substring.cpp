class Solution {
public:
    string longestPalindrome(string s) {
        int l,r;
        int left,right;
        int maxi =0;
        for(int i=0;i<s.size();i++){
            l=i;
            r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>maxi){
                    left=l;
                    right=r;
                    maxi = r-l+1;
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>maxi){
                    left=l;
                    right=r;
                    maxi = r-l+1;
                }
                l--;
                r++;
            }
        }
        string res="";
        for(int i=left;i<=right;i++){
            res+=s[i];
        }
        return res;
    }
};