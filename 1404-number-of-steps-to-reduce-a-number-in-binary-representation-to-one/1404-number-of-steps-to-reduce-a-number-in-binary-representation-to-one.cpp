class Solution {
public:
    int numSteps(string s) {
        int carry=0,op=0;
        int i=s.size()-1;
        while(i>=0){
            if(i==0 && carry==0) break;
            int c = s[i]-'0';
            
            if(carry^c){
                op+=2;
            }
            else{
                op+=1;
            }
            carry=carry|c;
            i--;
        }
        return op;
    }
};