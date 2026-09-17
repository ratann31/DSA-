class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        //step-1:find first decreasing element from the right
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }

        //step-2:find element just greater than nums[i]
        if(i>=0){
            int j=n-1;
            while(nums[j]<=nums[i]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
        //step-3:reverse the remaining part
        reverse(nums.begin()+i+1,nums.end());
    }
};