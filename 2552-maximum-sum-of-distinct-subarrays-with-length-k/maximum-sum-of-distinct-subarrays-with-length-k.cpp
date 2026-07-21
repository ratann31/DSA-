class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mpp;
        long long currSum = 0;
        long long ans = 0;

        int l = 0;

        for(int r = 0; r < nums.size(); r++) {

            currSum += nums[r];
            mpp[nums[r]]++;

            // Keep window size <= k
            if(r - l + 1 > k) {
                currSum -= nums[l];

                if(mpp[nums[l]] == 1)
                    mpp.erase(nums[l]);
                else
                    mpp[nums[l]]--;

                l++;
            }

            // Window size == k
            if(r - l + 1 == k && mpp.size() == k) {
                ans = max(ans, currSum);
            }
        }

        return ans;
    }
};