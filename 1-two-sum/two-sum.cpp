class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int>mpp;//{el,idx}
        for(int i=0;i<n;i++){
            int temp=target-nums[i];
            if(mpp.find(temp)!=mpp.end()){ //found in map
                return {i,mpp[temp]};
            }
            mpp[nums[i]]=i;
        }
        return {};
    }
};