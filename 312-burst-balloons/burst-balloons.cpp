class Solution {
public:
    int f(int l,int r,vector<int>&nums,vector<vector<int>>&dp){
        if(l>r)return 0;
        int maxi=0;
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        for(int i=l;i<=r;i++){
            int cost=nums[i]*nums[l-1]*nums[r+1]+f(l,i-1,nums,dp)+f(i+1,r,nums,dp);
            maxi=max(maxi,cost);
        }
        return dp[l][r]= maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,nums,dp);
    }
};