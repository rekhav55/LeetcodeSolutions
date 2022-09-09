class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& v) {
         int n = v.size();
    
    sort(v.begin(), v.end() ,[](vector<int>& a , vector<int>&b){
        
        if(a[0]==b[0]) return a[1]>b[1];
        else{
            return a[0]<b[0];
        }
    });
        
        
    
    int secondLast = n-2;
    int maxi = v[n-1][1];
    int res = 0 ;
        
        for(int i = secondLast;i>=0;i--){
            
            if(v[i][1] < maxi){
                res+=1;
                
            }
            
            maxi = max(maxi , v[i][1]);
            
            
        }
    
    
    return res;
    }
};