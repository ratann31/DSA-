class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int currSum=0;

        int l=0,r=0;
        int cnt=0;
        while(r<n){
            currSum+=nums[r];
            if(nums[r]==0)cnt++;

            if(cnt>k){
                while(cnt>k){
                    if(nums[l]==0){
                        cnt--;
                    }else{
                        currSum-=1;
                    }
                    l++;
                }
            }else{
                int len=r-l+1;
                ans=max(ans,len);
            }
            r++;
        }   
        return ans;
    }
};