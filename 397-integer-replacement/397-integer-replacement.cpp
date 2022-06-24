class Solution {
public:
    int integerReplacement(int num) {
        int moves=0;
        long n=num;
        while(n!=1){
            if(n%2==0){
                n=n/2;
            }else{
                if(n==3){
                    n--;
                    moves++;
                    continue;
                }
                
                int l=n-1,h=n+1;
                int lc=0,hc=0;
                while(l%2==0){
                    l/=2;
                    lc++;
                }
                
                while(h%2==0){
                    h/=2;
                    hc++;
                }
                
                if(hc>lc){
                    n++;
                }else{
                    n--;
                }
            }
            moves++;
        }
        return moves;
    }
};