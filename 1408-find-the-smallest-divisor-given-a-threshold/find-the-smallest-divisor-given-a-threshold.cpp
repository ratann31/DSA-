class Solution {
public:
    int findSum(vector<int>&nums,int x){
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=((nums[i]+x-1)/x);
        }
        return totalSum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int lo=1;
        int hi=*max_element(nums.begin(),nums.end());
        int ans;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int result=findSum(nums,mid);
            if(result>threshold){//total sum is greater so divide by larger no so the total sum reduces
              lo=mid+1;
            }else{
                hi=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};