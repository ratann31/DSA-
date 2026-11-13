class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        // Check whether both arrays have the same elements.
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
            mpp[target[i]]--;
        }

        for (auto it : mpp) {
            if (it.second != 0) return 0;
        }

        // suffixSorted[i] tells whether target[i...n-1]
        // is sorted in non-increasing order.
        vector<bool> suffixSorted(n, false);

        suffixSorted[n - 1] = true;

        for (int i = n - 2; i >= 0; i--) {
            suffixSorted[i] = (target[i] >= target[i + 1])
                              && suffixSorted[i + 1];
        }

        bool prefixSame = true;
        int count = 0;

        for (int i = 0; i < n; i++) {

            // Prefix must match and target suffix must be descending.
            if (prefixSame && suffixSorted[i]) {
                count++;
            }

            // Update prefix condition for the next index.
            if (nums[i] != target[i]) {
                prefixSame = false;
            }
        }

        return count;
    }
};