class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k<=1){
            return 0;
        }
        int n=nums.size();
        int product=1;
        int l=0,r=0;
        int ans=0;
        while(r<n){
            product*=nums[r];

            while(product>=k){
                product=product/nums[l];
                l++;
            }

            if(product<k){
                ans+=(r-l+1);
            }
            r++;
        }

        return ans;
    }
};