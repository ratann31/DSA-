class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        int largest=*max_element(nums.begin(),nums.end());
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        if(k==1){
           int ans=-1;
           for(int i=0;i<n;i++){
            if(nums[i]>ans && mpp[nums[i]]==1){
                ans=nums[i];
            }
           }
           return ans;
        }
        if(k==n){
            return largest;
        }
        int l=mpp[nums[0]];
        int r=mpp[nums[n-1]];

        if(l==1 && r>1){
            return nums[0];
        }
        if(l>1 && r==1){
            return nums[n-1];
        }
        if(l==1 && r==1){
            return max(nums[0],nums[n-1]);
        }
        return -1;
    }
};