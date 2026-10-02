class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int currCount=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                currCount++;
                ans=max(ans,currCount);
            }else{
                currCount=0;
            }
        }
        return ans;
    }
};