class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());

        for(int i=0;i<k;i++){
            ans += nums[i]*1LL*(max(1,mul));
            mul--;
        }

        return ans;
        
    }
};