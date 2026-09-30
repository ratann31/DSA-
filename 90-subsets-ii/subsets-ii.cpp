class Solution {
public:
    void f(int idx,vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums){
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
       
        f(idx+1,temp,ans,nums);
        while(idx+1<nums.size() && nums[idx]==nums[idx+1]){
            idx++;
        }
        temp.pop_back();

        f(idx+1,temp,ans,nums);


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;

        f(0,temp,ans,nums);
        
        return ans;
    }
};