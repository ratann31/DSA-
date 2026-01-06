class Solution {
public:
    void f(int idx,set<vector<int>>&ans,vector<int>temp,vector<int>& nums){
        //base case
        if(idx>=nums.size()){
            //check before pushing into the set
            if(ans.find(temp)==ans.end()){//not present into the set
                 ans.insert(temp);
            }
            return;
        }
        //take
        temp.push_back(nums[idx]);
        f(idx+1,ans,temp,nums);
        temp.pop_back();
        //not take
        f(idx+1,ans,temp,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>ans;
        vector<int>temp;
        f(0,ans,temp,nums);
        vector<vector<int>>res;
        for(auto &it:ans){
            res.push_back(it);
        }
        return res;
    }
};