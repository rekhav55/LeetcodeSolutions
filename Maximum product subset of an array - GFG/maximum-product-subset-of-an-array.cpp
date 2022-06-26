// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here  
        vector<int>neg;
        int mod = 1e9+7;
        int negt=0,pos=0,zero=0;
        long long int prod=1;
        for(int i=0;i<n;i++){
            if(a[i]<0){
                negt++;
                neg.push_back(a[i]);
            }
            else if(a[i]==0){
                zero++;
            }
            else{
                pos++;
                prod = (prod*a[i])%mod;
            }
        }
        
        if(pos>0){
            sort(neg.begin(),neg.end());
            if(neg.size()%2==0){
                for(int i=0;i<neg.size();i++) prod = (prod*neg[i])%mod;
            }
            else{
                for(int i=0;i<neg.size()-1;i++){
                    prod = (prod*neg[i])%mod;
                }
            }
        }
        if(pos==0){
            if(negt==1){
               if(zero==0) prod=neg[0];
               else{
                   prod=0;
               }
            }
            else{
                sort(neg.begin(),neg.end());
                if(neg.size()%2==0){
                    for(int i=0;i<neg.size();i++) prod = (prod*neg[i])%mod;
                }
                else{
                    for(int i=0;i<neg.size()-1;i++){
                        prod = (prod*neg[i])%mod;
                    }
                }
            }
            
        }
        
        return prod%mod;
        
        
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends