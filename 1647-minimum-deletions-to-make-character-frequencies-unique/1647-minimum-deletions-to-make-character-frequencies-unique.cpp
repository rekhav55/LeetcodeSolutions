class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        for(auto it:s){
            freq[it-'a']++;
        }
        
        sort(freq.begin(),freq.end(),greater<int>());
        int maxFreq=s.size();
        int cnt=0;
        for(int i=0;i<26 && freq[i]>0;i++){
            if(freq[i]>maxFreq){
                cnt = cnt+ (freq[i]-maxFreq);
                freq[i]=maxFreq;
            }
            
            maxFreq = max(0,freq[i]-1);
        }
        return cnt;
    }
};
