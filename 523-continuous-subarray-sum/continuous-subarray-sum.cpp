class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int>mpp;//{rem,idx}
        mpp[0]=-1;

        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];

            int rem=currSum%k;
            if(mpp.find(rem)!=mpp.end()){
                int len=i-mpp[rem];
                if(len>=2)return true;
            }
            if(mpp.find(rem)==mpp.end()){
                mpp[rem]=i;
            }
        }
        return false;
    }
};