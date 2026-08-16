class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //longest subarray containing at max one '0'
        int n=nums.size();
        unordered_map<int,int>mpp;
        int l=0,r=0;
        int maxLen=0;

        while(r<n){
            mpp[nums[r]]++;

            while(mpp[0]>1){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }

            maxLen=max(maxLen,r-l+1);
            r++;
        }

        return maxLen-1;

    }
};