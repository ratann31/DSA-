class Solution {
public:
    void f(int idx,vector<int>&temp,vector<int>&nums,vector<vector<int>>&ans){
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        f(idx+1,temp,nums,ans);
        temp.pop_back();
        f(idx+1,temp,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,temp,nums,ans);
        return ans;
    }
};