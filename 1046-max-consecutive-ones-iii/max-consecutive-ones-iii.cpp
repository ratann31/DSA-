class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int>mpp;//{el,freq}
        int l=0,r=0;
        int maxLen=0;
        while(r<n){
            mpp[nums[r]]++;

            while(mpp[0]>k){
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