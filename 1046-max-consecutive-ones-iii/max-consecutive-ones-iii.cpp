class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;//{cnt,freq}
        int l=0,r=0;

        int ans=0;

        while(r<n){
            mpp[nums[r]]++;

            while(mpp[0]>k){
                if(mpp[nums[l]]==1){
                    mpp.erase(nums[l]);
                }else{
                    mpp[nums[l]]--;
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};