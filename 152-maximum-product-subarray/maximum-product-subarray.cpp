class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int pre=1;
        int suffix=1;
        for(int i=0;i<n;i++){
            if(pre==0)pre=1;
            if(suffix==0)suffix=1;
            pre*=nums[i];
            suffix*=nums[n-i-1];
            ans=max(ans,max(pre,suffix));
            
        }
        return ans;
    }
};