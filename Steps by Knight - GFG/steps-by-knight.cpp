// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    // void dfs(int pr,int pc,int tr, int tc, vector<vector<int>>&chess,int &ans,int count){
    //     if(pr<=0 || pc<=0 || pr>=chess.size() || pc>=chess[0].size() || chess[pr][pc]==1) return;
    //     if(pr==tr && pc==tc){
    //         ans = min(ans,count);
    //         return;
    //     }
    //     chess[pr][pc]=1;
    //     dfs(pr+2,pc+1,tr,tc,chess,ans,count+1);
    //     dfs(pr+2,pc-1,tr,tc,chess,ans,count+1);
    //     dfs(pr-2,pc+1,tr,tc,chess,ans,count+1);
    //     dfs(pr-2,pc-1,tr,tc,chess,ans,count+1);
    //     dfs(pr+1,pc+2,tr,tc,chess,ans,count+1);
    //     dfs(pr-1,pc+2,tr,tc,chess,ans,count+1);
    //     dfs(pr+1,pc-2,tr,tc,chess,ans,count+1);
    //     dfs(pr-1,pc-2,tr,tc,chess,ans,count+1);
    //     chess[pr][pc]=0;
    // }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<int>>chess(N+1,vector<int>(N+1,0));
	    int m[8][2] = {{-2,-1},{-2,1},{2,1},{2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0],KnightPos[1]});
	    chess[KnightPos[0]][KnightPos[1]]=1;
	    int ans =0;
	    while(!q.empty()){
	        int sz = q.size();
	        for(int i=0;i<sz;i++){
	            pair<int,int>temp=q.front();
	            q.pop();
	            int r = temp.first;
	            int c = temp.second;
	            if(r==TargetPos[0] && c==TargetPos[1]) return ans;
	            for(int i=0;i<8;i++){
	                int rn = r + m[i][0];
	                int cn = c + m[i][1];
	                if(rn>0 && cn>0 && rn<=N && cn<=N && chess[rn][cn]==0){
	                    q.push({rn,cn});
	                    chess[rn][cn]=1;
	                }
	            }
	        }
	        ans++;
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends