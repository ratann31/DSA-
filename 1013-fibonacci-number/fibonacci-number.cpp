class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0)return 0;
        if(n==1)return 1;
        if(dp[n]!=-1){
            return dp[n];
        }
        int prev1=solve(n-1,dp);
        int prev2=solve(n-2,dp);

        return dp[n]=prev1+prev2;
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};