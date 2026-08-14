class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();

        int ans=INT_MAX;
        int l=0,r=0;

        int currSum=0;

        while(r<n){
            currSum+=nums[r];
            while(currSum>=target){
                ans=min(ans,r-l+1);
                currSum-=nums[l];
                l++;
            }
            r++;
        }

        if(ans==INT_MAX)return 0;
        return ans;
    }
};