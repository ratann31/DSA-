class Solution {
public:
    void solve(int idx,vector<vector<int>>&ans,vector<int>&temp,vector<int>& nums){
        //base case
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
        //take
        temp.push_back(nums[idx]);
        solve(idx+1,ans,temp,nums);
        temp.pop_back();
        //not take
        solve(idx+1,ans,temp,nums);
       // temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,ans,temp,nums);
        return ans;
    }
};