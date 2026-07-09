class Solution {
public:
    bool isValid(vector<int>&nums,int mid,int th){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            int a = nums[i];
            int b = mid;
            int res=(a+b-1)/b;
            sum+=res;
        }
        if(sum<=th)return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int lo=1;
        int hi=*max_element(nums.begin(),nums.end());

        int ans= -1;

        while(lo<=hi){
            int mid = (lo+hi)>>1;
            if(isValid(nums,mid,threshold)==true){
                hi=mid-1;
                ans=mid;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};