class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return {nums[0]};
        vector<int>ans;
        vector<int>left(n),right(n);
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]=max(nums[i],left[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(nums[i],right[i+1]);
        }
        ans.push_back(nums[0]);
        for(int i=1;i<n-1;i++){
            int lmax=left[i-1];
            int rmax=right[i+1];

            if(nums[i]<=lmax && nums[i]<=rmax){
                continue;
            }

            if(nums[i]>lmax || nums[i]>rmax){
                ans.push_back(nums[i]);
            }
        }
        ans.push_back(nums[n-1]);
        return ans;
    }
};