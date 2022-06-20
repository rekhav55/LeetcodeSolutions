// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>res;
        int total=r*c;
        int cnt=0;
        int minCol=0,minRow=0,maxCol=c-1,maxRow=r-1;
        while(cnt<total){
            if(cnt<total){
                for(int i=minRow,j=minCol;j<=maxCol;j++){
                    res.push_back(matrix[i][j]);
                    cnt++;
                }
            }
            minRow++;
            if(cnt<total){
                for(int i=minRow,j=maxCol;i<=maxRow;i++){
                    res.push_back(matrix[i][j]);
                    cnt++;
                }
            }
            maxCol--;
            if(cnt<total){
                for(int i=maxCol,j=maxRow;i>=minCol;i--){
                  res.push_back(matrix[j][i]);
                  cnt++;
                }
            }
            maxRow--;
            if(cnt<total){
                for(int i=maxRow,j=minCol;i>=minRow;i--){
                    res.push_back(matrix[i][j]);
                    cnt++;
                }
            }
            minCol++;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends