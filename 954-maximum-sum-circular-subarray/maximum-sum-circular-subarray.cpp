class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int curr1=nums[0];
        int maxSum=nums[0];

        int curr2=nums[0];
        int minSum=nums[0];

        for(int i=1;i<n;i++){
           curr1=max(curr1+nums[i],nums[i]);
           maxSum=max(maxSum,curr1);

           curr2=min(curr2+nums[i],nums[i]);
           minSum=min(minSum,curr2);
        }

        int total=accumulate(nums.begin(),nums.end(),0);
        int circularMax=total-minSum;

        if(circularMax==0){
            return maxSum;
        }
        return max(maxSum,circularMax);


        
    }
};