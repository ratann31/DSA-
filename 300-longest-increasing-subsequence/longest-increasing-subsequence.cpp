class Solution {
public:
    int solve(int idx,vector<int>&nums,int prev,vector<vector<int>>&dp){
        if(idx>=nums.size()){
            return 0;
        }
        if (prev!=-1 && dp[idx][prev]!=-1){
            return dp[idx][prev];
        }
        int take=0;
        if(prev==-1 || nums[prev]<nums[idx]){
            take=1+solve(idx+1,nums,idx,dp);
        }
        int skip=solve(idx+1,nums,prev,dp);
        if(prev!=-1){
            dp[idx][prev]=max(take,skip);
        }
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,nums,-1,dp);
    }
};