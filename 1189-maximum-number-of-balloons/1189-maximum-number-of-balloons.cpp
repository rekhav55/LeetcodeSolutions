class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>temp(26,0);
        for(int i=0;i<text.size();i++){
            temp[text[i]-'a']++;
        }
        int ans =0;
        while(true){
            if(temp[0]>=1 && temp[1]>=1 && temp[11]>=2 && temp[13]>=1 && temp[14]>=2){
                temp[0]--;
                temp[1]--;
                temp[11]-=2;
                temp[13]--;
                temp[14]-=2;
                ans++;
            }
            else break;
            
        }
        return ans;
    }
};