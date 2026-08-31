class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer>mpp=new HashMap<>();

        for(int i=0;i<nums.length;i++){
            int curr=nums[i];
            int rem=target-curr;

            if(mpp.containsKey(rem)==true){
                int[] arr = new int[2];
                arr[0]=mpp.get(rem);
                arr[1]=i;

                return arr;
            }

            mpp.put(curr,i);
        }

        return new int[0];
    }
}