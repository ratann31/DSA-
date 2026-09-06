class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;//{rem,freq}
        mpp[0]=1;
        int currSum=0;
        int ans=0;

        for(int i=0;i<n;i++){
            currSum+=nums[i];
            int rem=currSum%k;

            if(rem<0){
                rem+=k;
            }

            if(mpp.find(rem)!=mpp.end()){
                ans+=mpp[rem];
            }
            mpp[rem]++;
        }

        return ans;
    }
};