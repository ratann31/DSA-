class Solution {
    public int singleNumber(int[] nums) {
        int xr=nums[0];

        for(int i=1;i<nums.length;i++){
            xr=xr^nums[i];
        }

        return xr;

    }
}