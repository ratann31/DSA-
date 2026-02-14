class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                hi=mid-1;
            }
            else lo=mid+1;
        }
        auto it=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return it;
    }
};