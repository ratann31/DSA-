class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int leftVal,rightVal;
            if(mid==0){
                leftVal=INT_MIN;
            }else{
                leftVal=nums[mid-1];
            }
            if(mid==n-1){
                rightVal=INT_MIN;
            }else{
                rightVal=nums[mid+1];
            }
            //if peak found
            if(nums[mid]>leftVal && nums[mid]>rightVal){
                ans=mid;
                break;
            }
            else if(nums[mid]<rightVal){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};