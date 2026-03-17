class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();//rows
        int n=obstacleGrid[0].size();//columns
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        if(obstacleGrid[0][0]!=1){
            dp[0][0]=1;
        }else{
            dp[0][0]=0;
        }
        //fill first row and columns
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]!=1){
                dp[i][0]=1;
            }else if(obstacleGrid[i][0]==1){
                break;
            }
        }
        for(int j=0;j<n;j++){
            if(obstacleGrid[0][j]!=1){
                dp[0][j]=1;
            }else if(obstacleGrid[0][j]==1){
                break;
            }
        }
        //fill remaining cells
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]!=1){
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[m-1][n-1];
    }
};