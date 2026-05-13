class Solution {
public:
    int mod=1e9+7;
    int solve(int n,int target,int k,vector<vector<int>>&dp){
        if(n==0){
            if(target==0)return 1;
            return 0;
        }
        //if(target==0)return 1;
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        long long ways=0;
        for(int i=1;i<=k;i++){
            if(target>=i){
                ways=(ways+solve(n-1,target-i,k,dp))%mod;
            }
        }

        return dp[n][target]=ways%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,target,k,dp);
    }
};