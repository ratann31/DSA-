class Solution {
public:
    void f(int idx,vector<int>&temp,vector<vector<int>>&ans,vector<int>&candidates,int t){
        if(t==0){
            ans.push_back(temp);
            return;
        }

        if(idx==candidates.size()){
            return;
        }

        //take current element
        if(candidates[idx]<=t){
            temp.push_back(candidates[idx]);
            f(idx,temp,ans,candidates,t-candidates[idx]);
            temp.pop_back();
        }
        //skip current element
        f(idx+1,temp,ans,candidates,t);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();

        vector<vector<int>>ans;
        vector<int>temp;

        f(0,temp,ans,candidates,target);

        return ans;
    }
};