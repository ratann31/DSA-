class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int l=0,r=0;
        int z=0;
        while(r<n){
            if(nums[r]==0){
                z++;
            }
            while(z>1){
                if(nums[l]==0){
                    z--;
                }l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans-1;
    }
};