class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>freq(10,0);
        for(int i=0;i<digits.size();i++){
            freq[digits[i]]++;
        }
        vector<int>res;
        for(int i=100;i<=999;i+=2){
            int ones = i%10;
            int tens = (i/10)%10;
            int hundreds = i/100;
            freq[ones]--;
            freq[tens]--;
            freq[hundreds]--;
            if(freq[ones]>=0 && freq[tens]>=0&&freq[hundreds]>=0){
                res.push_back(i);
            }
            freq[ones]++;
            freq[tens]++;
            freq[hundreds]++;
        }
        return res;
    }
};