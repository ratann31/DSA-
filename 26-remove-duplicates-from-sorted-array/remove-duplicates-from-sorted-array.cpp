class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        int l = 0, r=1;
        while( l < r&&r<n){
           if(nums[l]!=nums[r]){
            l++;
            nums[l]=nums[r];
           }
           r++;
        }
        return l+1;
    }
};