// { Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int MOD= 1000000007;
   long long int power(int a, long long int b) {
       
       if(b < 1){
           return 1;
       }
       
      long long int halfPower= power(a,b/2); 
      long long int res  = 1;
      if(b % 2 == 0){
          res *= (halfPower) % MOD * (halfPower) % MOD;
      }else{
          res *= (halfPower) % MOD * (halfPower) % MOD * a;
      }  
       return res % MOD;
   }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        long long b;
        cin >> a >> b;
        Solution ob;
        cout << ob.power(a, b) << endl;
    
    }
    return 0; 
} 


  // } Driver Code Ends