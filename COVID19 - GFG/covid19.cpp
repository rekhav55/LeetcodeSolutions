#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n,m;
	    cin>>n>>m;
	    int mat[n][m];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            int x;
	            cin>>x;
	            mat[i][j]=x;
	        }
	    }
	    
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(mat[i][j]==0){
	                q.push(make_pair(i,j));
	            }
	        }
	    }
	    int t=-1;
	    while(!q.empty()){
	        int sz = q.size();
	        for(int i=0;i<sz;i++){
	            pair<int,int>temp = q.front();
	            q.pop();
	            int row = temp.first;
	            int col = temp.second;
	            mat[row][col]=-1;
	            if(row-1>=0 && mat[row-1][col]==1){
	                q.push(make_pair(row-1,col));
	                mat[row-1][col]=-1;
	            }
	            if(col+1<m && mat[row][col+1]==1){
	                q.push(make_pair(row,col+1));
	                mat[row][col+1]=-1;
	            }
	            if(row+1<n && mat[row+1][col]==1){
	                q.push(make_pair(row+1,col));
	                mat[row+1][col]=-1;
	            }
	            if(col-1>=0 && mat[row][col-1]==1){
	                q.push(make_pair(row,col-1));
	                mat[row][col-1]=-1;
	            }
	        }
	        t++;
	    }
	    cout<<t<<endl;
	}
	   
	return 0;
}