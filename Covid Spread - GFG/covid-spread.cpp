// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        //code here
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<hospital.size();i++){
            for(int j=0;j<hospital[0].size();j++){
                if(hospital[i][j]==2){
                    q.push(make_pair(i,j));
                }
                if(hospital[i][j]==1){
                    count++;
                }
            }
        }
        int t=-1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                pair<int,int>temp = q.front();
                q.pop();
                int row = temp.first;
                int col = temp.second;
                
                if(row-1>=0 && hospital[row-1][col]==1){
                    q.push(make_pair(row-1,col));
                    hospital[row-1][col]=2;
                    count--;
                }
                if(row+1<hospital.size() && hospital[row+1][col]==1){
                    q.push(make_pair(row+1,col));
                    hospital[row+1][col]=2;
                    count--;
                }
                if(col-1>=0 && hospital[row][col-1]==1){
                    q.push(make_pair(row,col-1));
                    hospital[row][col-1]=2;
                    count--;
                }
                if(col+1<hospital[0].size() && hospital[row][col+1]==1){
                    q.push(make_pair(row,col+1));
                    hospital[row][col+1]=2;
                    count--;
                }
            }
            t++;
        }
        
        if(count!=0) return -1;
        return t;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends