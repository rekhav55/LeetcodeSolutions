class Solution {
public:
    int dp[1001];

int solve(int x,vector<vector<int>>& a,int shelfwidth)
{  //here we check for each shelves and take minmum of the cases where we can place some books on that shelve or shift it in upper shelves
    int i,j,n=a.size();
    
    int ans=INT_MAX;
    int wid=0;
    if(x==n) return 0;
    
    int s=0; int mxh=0;
    
    if(dp[x]!=-1) return dp[x];
    
for(i=x;i<n;i++)
{ 

  if(s+a[i][0]<=shelfwidth)//if width is available to place book
  {  
      if(s!=0)//place minimum 1 book on each shelves
      {ans=min(ans,mxh+solve(i,a,shelfwidth));}// if we shift remaining books to upper shelves
      
       mxh=max(a[i][1],mxh);//if we arrange books in this shelve ,find max height of books
      
    s+=a[i][0];//check for width
  }
    else{
        //if book width is greater than remaoining width
		//we will have to shift on upper shelves
       return dp[x]=min(ans,mxh+solve(i,a,shelfwidth));
      
    }

}
    ans=min(ans,mxh);//find maximum height if books are arranged in many ways
    
    return dp[x]=ans;
    
}

int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    memset(dp,-1,sizeof(dp));
    return solve(0,books,shelfWidth);
}
};