class Solution {
public:
   int tab[30][60];
    int fun(int arr[],int n, int sum){
        if(sum==0)
            return 1;
        if(n==0)
            return 0;
        if(tab[n][sum]!=-1)
            return tab[n][sum];
        if(arr[n-1]<=sum)
            tab[n][sum]=max(arr[n-1]*fun(arr,n,sum-arr[n-1]),fun(arr,n-1,sum));
        else
            tab[n][sum]=fun(arr,n-1,sum);
        return tab[n][sum];
    }
    int integerBreak(int n) {
        if(n==3)
            return 2;
        if(n==5)
            return 6;
        int arr[n/2];
        for(int i=0;i<n/2;i++)
            arr[i]=i+1;
        int sum=n;
        memset(tab,-1,sizeof(tab));
        return fun(arr,n/2,sum);
    }
    
    
};