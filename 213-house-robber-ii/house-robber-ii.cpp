class Solution {
public:
    int f(int idx,vector<int>&arr,vector<int>&dp){
        if(idx<0)return 0;
        if(idx==0)return arr[0];

        if(dp[idx]!=-1){
            return dp[idx];
        }

        int take = arr[idx]+f(idx-2,arr,dp);
        int skip = f(idx-1,arr,dp);

        return dp[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>v1,v2;

        vector<int>dp1(n-1,-1);
        vector<int>dp2(n-1,-1);
        
        for(int i=0;i<n-1;i++){
            v1.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            v2.push_back(nums[i]);
        }
        int ans1=f(n-2,v1,dp1);
        int ans2=f(n-2,v2,dp2);

        return max(ans1,ans2);
    }
};