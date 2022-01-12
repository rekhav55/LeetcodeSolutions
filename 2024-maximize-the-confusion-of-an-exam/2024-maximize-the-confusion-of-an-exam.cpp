class Solution {
public:
    int helper(char c, string ans, int key){
        int i=0,j=0,res=INT_MIN;
        int count=0;
        for(j=0;j<ans.size();j++){
            if(ans[j]==c){
                count++;
            }
            while(count>key){
                if(ans[i]==c) count--;
                i++;
            }
            res = max(res,j-i+1);
        }
        return res;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper('T', answerKey,k), helper('F',answerKey, k));
    }
};