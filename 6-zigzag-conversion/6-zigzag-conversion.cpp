class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string>rows(min(numRows,(int)s.size()));
        int curr=0;
        bool flag=false;
        for(char c:s){
            rows[curr]+=c;
            if(curr==0 || curr==numRows-1) flag=!flag;
            curr+= flag?1:-1;
        }
        
        string res="";
        for(int i=0;i<rows.size();i++){
            res+=rows[i];
        }
        return res;
    }
};
