class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         vector<int>hash(26,0);
        
        for(auto it:tasks){
            hash[it-'A']++;
        }
        
        sort(hash.begin(),hash.end());
        int max_val = hash[25]-1;//for last char not need slot
        
        int slots = (max_val)*n;//total slots unit
        
        for(int i=24;i>=0;i--){
            slots-=min(hash[i],max_val);
        }
        
        int length = tasks.size();
        
        return (slots>0)?slots+length:length;
        
    }
};