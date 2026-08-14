class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int ans=0;
        int l=0,r=0;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp[nums[r]]>k){
                mpp[nums[l]]--;
                l++;
            }
            int len=r-l+1;
            ans=max(ans,len);
            r++;
        }
        return ans;
    }
};