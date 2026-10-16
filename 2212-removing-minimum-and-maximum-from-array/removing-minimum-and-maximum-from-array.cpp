class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        int minIdx,maxIdx;
        int mn=INT_MAX,mx=INT_MIN;
        for(int i=0;i<n;i++){
           if(nums[i]<mn){
            mn=nums[i];
            minIdx=i;
           }
           if(nums[i]>mx){
            mx=nums[i];
            maxIdx=i;
           }
        }
        int ans1=max(minIdx,maxIdx)+1;
        int ans2=n-min(minIdx,maxIdx);
        int ans3=min(minIdx,maxIdx)+1+(n-max(minIdx,maxIdx));

        return min({ans1,ans2,ans3});
    }
};