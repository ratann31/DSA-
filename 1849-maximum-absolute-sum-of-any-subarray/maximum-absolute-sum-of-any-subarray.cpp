class Solution {
public:
    int findMax(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }

    int findMin(vector<int>& nums) {
        int currSum = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currSum = min(nums[i], currSum + nums[i]);
            minSum = min(minSum, currSum);
        }

        return minSum;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = findMax(nums);
        int minSum = findMin(nums);

        return max(maxSum, abs(minSum));
    }
};