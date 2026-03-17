class Solution {
public:
    int f(int i,int j,vector<vector<int>>&grid,int m,int n,vector<vector<int>>&dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }else if(i==m-1){
            return grid[i][j]+f(i,j+1,grid,m,n,dp);
        }else if(j==n-1){
            return grid[i][j]+f(i+1,j,grid,m,n,dp);
        }
        return dp[i][j]=grid[i][j]+min(f(i,j+1,grid,m,n,dp),f(i+1,j,grid,m,n,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();//rows
        int n=grid[0].size();//columns
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(0,0,grid,m,n,dp);
        //tabulation
        vector<vector<int>>dp(m,vector<int>(n,0));
        //fill first row and first col of dp
        dp[0][0]=grid[0][0];
        for(int j=1;j<n;j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        //fill remaining rows and columns
        //dp[i][j]=min sum to reach till dp[i][j] fron dp[0][0]
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};