class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
             int left =0;
             int right = tokens.size()-1; 
             int score =0;
             while (left <= right){
                 if ( tokens[left] <= power) {
                     power-=tokens[left];
                     left++;
                     score++;
                 }
                 else if ( score >=1 && left != right) 
                 {
                     power+=tokens[right];
                     right--;
                     score--;
                 }
                 else {
             right--;
                     }
             }
             return score;
    }
};