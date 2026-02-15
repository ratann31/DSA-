class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        vector<long long>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                dp[i]=max(dp[i-1],nums[i]+(i>=2?dp[i-2]:0));
            }else{
                dp[i]=nums[i]+dp[i-1];
            }
        }
        return dp[n-1];
    }
};