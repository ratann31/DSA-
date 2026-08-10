class Solution {
public:
    void f(int idx,int t,vector<int>&temp,vector<vector<int>>&ans,vector<int>&candidates){
            if(t==0){
                ans.push_back(temp);
                return;
            }
            if(idx>=candidates.size() || candidates[idx]>t){
                return;
            }
            //take
            temp.push_back(candidates[idx]);
            f(idx+1,t-candidates[idx],temp,ans,candidates);
            temp.pop_back();
            //handle duplicates after taking
            while(idx+1< candidates.size() && candidates[idx]==candidates[idx+1]){
                idx++;
            }
            //not take 
            f(idx+1,t,temp,ans,candidates);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        f(0,target,temp,ans,candidates);
        return ans;
    }
};