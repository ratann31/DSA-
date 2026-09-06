class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int currSum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];

            int rem=currSum-k;
            if(mpp.find(rem)!=mpp.end()){
                ans+=mpp[rem];
            }

            mpp[currSum]++;
        }

        return ans;
    }
};