class Solution {
public:
    void solve(int idx,int t,vector<int>&ds,vector<vector<int>>&ans,vector<int>& candidates){
        if(idx>=candidates.size() || t<0){
            return;
        }
        if(t==0){
           ans.push_back(ds);
           return;
        }
        //pick
        ds.push_back(candidates[idx]);
        solve(idx,t-candidates[idx],ds,ans,candidates);
        ds.pop_back();
        //not pick
        solve(idx+1,t,ds,ans,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,target,ds,ans,candidates);
        return ans;
    }
};