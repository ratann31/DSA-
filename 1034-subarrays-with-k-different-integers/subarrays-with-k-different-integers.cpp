class Solution {
public:
    int f(vector<int>&arr,int k){
        unordered_map<int,int>mpp;

        int l=0,r=0;
        int ans=0;

        while(r<arr.size()){
            mpp[arr[r]]++;

            while(mpp.size()>k){
                mpp[arr[l]]--;

                if(mpp[arr[l]]==0){
                    mpp.erase(arr[l]);
                }
                l++;
            }

            ans+=r-l+1;
            r++;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();

        return f(nums,k)-f(nums,k-1);
    }
};