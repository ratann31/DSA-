class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int currMax=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                currMax+=1;
                ans=max(ans,currMax);
            }else{
                currMax=0;
            }
        }
        return ans;
    }
};