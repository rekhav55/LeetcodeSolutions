class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        int cnt=0;
        int odd=0;
        for(auto it:mp){
            if(it.second%2==0){
                cnt+=it.second;
            }
            else{
                odd = true;
                cnt+=(it.second-1);
            }
        }
        
//         for(auto it:mp){
//             if(it.second%2!=0){
                
//             }
//         }
        
        if(odd==true) cnt+=1;
        return cnt;
    }
};