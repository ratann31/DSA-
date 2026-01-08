class Solution {
public:
    void f(int idx,vector<int>&temp,set<vector<int>>&st,vector<int>&nums){
        if(idx>=nums.size()){
            if(st.find(temp)==st.end()){
                st.insert(temp);
            }
            return;
        }
        temp.push_back(nums[idx]);
        f(idx+1,temp,st,nums);
        temp.pop_back();
        f(idx+1,temp,st,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int>temp;
        f(0,temp,st,nums);
        vector<vector<int>>ans;
        for(auto &it:st){
            ans.push_back(it);
        }
        return ans;

    }
};