class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        long long currSum=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<k;i++){
           currSum+=nums[i];
           mpp[nums[i]]++;
        }
        int l=0,r=k-1;
        while(l<n && r<n){
            if(mpp.size()==k){
                ans=max(ans,currSum);
            }
            currSum-=nums[l];
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0){
                mpp.erase(nums[l]);
            }
            l++;
            r++;
            if(r<n){
                currSum+=nums[r];
                mpp[nums[r]]++;
            }
        }
        return ans;
        
    }
};