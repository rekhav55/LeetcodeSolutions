class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            unordered_map<char,int> m;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(m.find(board[i][j])!=m.end())return false;
                m[board[i][j]]++;
            }
        }
        for(int i=0;i<9;i++){
            unordered_map<char,int> m;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')continue;
                if(m.find(board[j][i])!=m.end())return false;
                m[board[j][i]]++;
            }
        }
        
        int arr[][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        
        int v[][2]={{1,1},{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7}};
        
        for(int i=0;i<9;i++){
            
            unordered_map<char,int> m;
            
            int x=v[i][0],y=v[i][1];
            if(board[x][y]!='.')m[board[x][y]]++;
            for(int j=0;j<8;j++){
                if(board[x+arr[j][0]][y+arr[j][1]]=='.')continue;
                if(m.find(board[x+arr[j][0]][y+arr[j][1]])!=m.end())return false;
                m[board[x+arr[j][0]][y+arr[j][1]]]++;
            }  
        }
        return true;
        
    }
};