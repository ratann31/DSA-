class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;

            if(mpp[nums[i]]==(n/3)+1){
                res.push_back(nums[i]);
            }
            if(res.size()==2)break;
        }
        return res;

    }
};