class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>dp(n,1); //lis ending at i
        vector<int>count(n,1); //count of lis ending at i

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j]+1==dp[i]){
                        count[i]+=count[j];
                    }else if(dp[j]+1>dp[i]){
                        dp[i]=dp[i]+1;
                        count[i]=count[j];
                    }
                }
            }
        }
        int mxVal=*max_element(dp.begin(),dp.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==mxVal){
                ans+=count[i];
            }
        }
        return ans;

    }
};