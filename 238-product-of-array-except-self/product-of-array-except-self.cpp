class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0),suffix(n,0);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        for(int j=n-2;j>=0;j--){
            suffix[j]=suffix[j+1]*nums[j];
        }
        vector<int>ans(n,0);
        int l=1,r=1;
        ans[0]=suffix[1];
        ans[n-1]=prefix[n-2];
        for(int i=1;i<=n-2;i++){
            ans[i]=prefix[i-1]*suffix[i+1];
        }
        return ans;

    }
};