class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n =digits.size();
        bool flag=false;
        for(int i=n-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]=digits[i]+1;
                flag=true;
                break;
            }
            else{
                digits[i]=0;
            }
        }
        if(flag==false){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};