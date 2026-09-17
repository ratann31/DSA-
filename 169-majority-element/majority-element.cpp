class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();

        int count=0;
        int candidate=-1;

        for(int i=0;i<n;i++){
            if(count==0){
                candidate = nums[i];
                count++;
            }else if(nums[i]==candidate){
                count++;
            }else{
                //nums[i]!=candidate
                count--;
            }
        }

        return candidate;
    }
};