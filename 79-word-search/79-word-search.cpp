class Solution {
public:
    bool findWord(int i, int j, string &word, vector<vector<char>>&b, int idx){
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size() || word[idx]!=b[i][j] || b[i][j]=='0') return false;
        char temp=b[i][j];
        b[i][j]='0';
        idx++;
        if(idx==word.size()) return true;
        bool res = findWord(i+1,j,word,b,idx)||findWord(i-1,j,word,b,idx)||findWord(i,j+1,word,b,idx)||findWord(i,j-1,word,b,idx);
        b[i][j]=temp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(findWord(i,j,word,board,0)){
                    return true;
                }
            }
        }
        return false;
    }
};