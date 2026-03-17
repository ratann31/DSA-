class Solution {
public:
    int f(int row,int col,vector<vector<int>>&triangle,int n,vector<vector<int>>&dp){
        if(row==n-1){
            return triangle[row][col];
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int down=triangle[row][col]+f(row+1,col,triangle,n,dp);
        int downRight=triangle[row][col]+f(row+1,col+1,triangle,n,dp);

        return dp[row][col]=min(down,downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();//rows
        int m=triangle[n-1].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return f(0,0,triangle,n,dp);
        vector<vector<int>>dp(n,vector<int>(n,0));
        dp[0][0]=triangle[0][0];
        //fill first column
        for(int i=1;i<n;i++){
            dp[i][0]=triangle[i][0]+dp[i-1][0];
        }
        //fill last cell of each row-> can come fron top left diagonal only
        for(int i=1;i<n;i++){
            int j=triangle[i].size()-1;
            dp[i][j]=triangle[i][j]+dp[i-1][j-1];
        }
        //fill remaining cells
        for(int i=1;i<n;i++){
            for(int j=1;j<triangle[i].size()-1;j++){
                int top=triangle[i][j]+dp[i-1][j];
                int diagonal=triangle[i][j]+dp[i-1][j-1];

                dp[i][j]=min(top,diagonal);
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<triangle[n-1].size();j++){
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};