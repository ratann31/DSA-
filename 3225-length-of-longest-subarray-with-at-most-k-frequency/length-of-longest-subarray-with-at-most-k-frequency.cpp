class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int maxLen=0;
        unordered_map<int,int>mpp;//{nums,freq}
        int l=0,r=0;
        while(r<n){
            mpp[nums[r]]++;

            while(mpp[nums[r]]>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }

            maxLen=max(maxLen,r-l+1);
            r++;
        }

        return maxLen;
    }
};