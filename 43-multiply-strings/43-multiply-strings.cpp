class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int>res(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                res[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                res[i+j]+= res[i+j+1]/10;
                res[i+j+1]=res[i+j+1]%10;
            }
        }
        
        int i=0;
        bool flag=false;
        string ans="";
        while(i<res.size()){
            if(res[i]==0 && flag==false){
                i++;
            }
            else{
                flag=true;
                ans += res[i]+'0';
                i++;
            }
        }
        if(ans.size()==0){
            return "0";
        }
        return ans;
    }
};