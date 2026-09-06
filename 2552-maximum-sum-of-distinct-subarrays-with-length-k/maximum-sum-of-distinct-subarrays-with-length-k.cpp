class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        int l=0,r=0;
        unordered_map<int,int>mpp;
        long long sum=0;
        while(r<n){
            sum+=nums[r];
            mpp[nums[r]]++;
            
            while(mpp[nums[r]]>1 || mpp.size()>k){
                if(mpp[nums[l]]==1){
                    mpp.erase(nums[l]);
                }else{
                    mpp[nums[l]]--;
                }
                sum-=nums[l];
                l++;
                
            }
            if(mpp.size()==k){
                ans=max(ans,sum);
            }
            r++;
        }

        return ans;
    }
};