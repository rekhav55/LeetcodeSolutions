class Solution {
public:
//     int f(int idx, vector<int>&price, int buy){
//         if(idx==price.size()) return 0;
//         int pick=INT_MIN, no_pick=INT_MIN;
//         if(buy==0){
//             pick = -price[idx]+f(idx+1,price,1);
//             no_pick = f(idx+1,price,buy);
//         }
//         else{
//             pick = price[idx]+f(idx+1,price,0);
//             no_pick = f(idx+1,price,buy);
//         }
        
//         return max(pick,no_pick);
//     }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = prices[n-1];
        int profit = 0;
        for(int i=prices.size()-1;i>=0;i--){
            maxi = max(maxi,prices[i]);
            profit = max(profit, abs(maxi-prices[i]));
        }
        return profit;
    }
};