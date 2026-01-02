class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int currZero=0;
        int ans=0;
        while(r<n){ 
            if(nums[r]==0){
                currZero++;
            }
            while(currZero>k){
                if(nums[l]==0){
                    currZero--;
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};