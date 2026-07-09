class Solution {
public:
    bool isValid(vector<int>&nums,int mid,int k){
       int count = 1;
       int currSum=0;

       for(int i=0;i<nums.size();i++){
        currSum+=nums[i];
        if(currSum>mid){
            count++;
            currSum=nums[i];
        }
       }
       return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(lo<=hi){
            int mid = (lo+hi)>>1;
            if(isValid(nums,mid,k)==true){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};