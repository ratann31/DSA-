class Solution {
public:
    int f(int idx,vector<int>&nums,int t, vector<vector<int>>&dp){
        if(t==0){
            return 1;
        }
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx][t]!=-1){
            return dp[idx][t];
        }
        int take = 0;
        if(nums[idx]<=t){
            take = f(0,nums,t-nums[idx],dp);
        }
        int not_take = f(idx+1,nums,t,dp);

        return dp[idx][t] = take+not_take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(0,nums,target,dp);
    }
};