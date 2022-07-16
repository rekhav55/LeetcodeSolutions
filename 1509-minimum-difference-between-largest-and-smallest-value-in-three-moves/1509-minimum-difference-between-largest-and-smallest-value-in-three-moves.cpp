class Solution {
public:
    int minDifference(vector<int>& a) {
        int n = a.size() , k = 3; if(n<=4) return 0; 
        sort(begin(a),end(a)); int ans = INT_MAX;
        
        int i = 3 , j= a.size()-1;
        
        while(i>=0){
            ans = min(ans,a[j]-a[i]);
            i--;j--;
        }
        return ans;
        
    }
};
