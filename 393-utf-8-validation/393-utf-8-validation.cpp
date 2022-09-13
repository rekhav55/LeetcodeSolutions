class Solution {
 string convertToBinary(int n){
        string s = "";
        while(n>0){
            string now = to_string(n%2);
            s = now + s;
            n /= 2;
        }
        while(s.length() < 8)
            s = '0' + s;
        return s;
    }
public:
    bool validUtf8(vector<int>& data) {
        for(int i=0;i<data.size();i++){
            string now = convertToBinary(data[i]);
            int countNumber = 0;
            for(int j=0;j<8;j++){
                if(now[j] == '1') countNumber++;
                else break;
            }
            if(countNumber == 1 or countNumber > 4) return false;
            int k = 1;
            while(k < countNumber){
                i++;
                if(i>=data.size()) return false;
                string cur = convertToBinary(data[i]);
                if(cur[0] != '1' or cur[1] != '0') return false;
                k++;
            }
        }
        return true;
    }
};