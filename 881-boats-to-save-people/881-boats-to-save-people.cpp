class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int cnt=0;
        int i=0,j=p.size()-1;
        unordered_map<int,int>mp;
        while(i<j){
            if(p[i]+p[j]<=limit){
                cnt++;
                mp[p[i]]++;
                mp[p[j]]++;
                j--;
                i++;
            }
            else{
                j--;
            }
        }
        // for(int i=0;i<p.size();i++){
        //     if(p[i]<=limit && mp.find(p[i])!=mp.end()){
        //         if(mp[p[i]]==0) cnt++;
        //         else mp[p[i]]--;
        //     }
        //     else if(p[i]<=limit && mp.find(p[i])==mp.end()) cnt++;
        // }
        // return cnt;
        int rem = p.size()-(cnt*2);
        cnt = cnt+rem;
        return cnt;
    }
};