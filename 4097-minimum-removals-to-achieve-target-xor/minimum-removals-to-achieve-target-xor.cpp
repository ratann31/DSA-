class Solution {
public:
 int MAXX = 16384;
    int f(int idx,int currXor, vector<int>&nums,int t,vector<vector<int>>&dp){
        if(idx==nums.size()){
            if(currXor==t)return 0;
            return -1e9;
        }
        if(dp[idx][currXor]!=-1){
            return dp[idx][currXor];
        }
        //take
        int take=f(idx+1,currXor^nums[idx],nums,t,dp);
        if(take!=-1e9)take+=1;
        //skip
        int skip=f(idx+1,currXor,nums,t,dp);

        return dp[idx][currXor]=max(take,skip);
    }
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(MAXX,-1));
        int maxSubset=f(0,0,nums,target,dp);

        if(maxSubset<0)return -1;
        return n-maxSubset;
    }
};