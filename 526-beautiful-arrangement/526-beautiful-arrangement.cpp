class Solution {
public:
    int ans=0;
    
    void permu(int n,int start,vector<int>&arr)
    {
         if(start==n)
        {
            ans++;
            return ;
        }
        for(int i=start;i<n;i++)
        {
            if((start+1)%arr[i]==0||arr[i]%(start+1)==0)
            {
                swap(arr[i],arr[start]);
                permu(n,start+1,arr);
                swap(arr[i],arr[start]);
            }
        }
    }
    
    int countArrangement(int n,int start=0) {
        
        vector<int>arr;
        
       for(int i=1;i<=n;i++)
       arr.push_back(i);
        
        permu(n,0,arr);
        
        return ans;
    }
};

