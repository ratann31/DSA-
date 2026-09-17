class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();

        int currSum=0;
        int maxSum=nums[0];

        for(int i=0;i<n;i++){
            if(nums[i]>=currSum+nums[i]){
                currSum=nums[i];
            }else{
                currSum+=nums[i];
            }
            maxSum=max(maxSum,currSum);
        }

        return maxSum;
    }
};