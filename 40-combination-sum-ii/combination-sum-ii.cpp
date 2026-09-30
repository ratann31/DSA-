class Solution {
public:
    void f(int idx,int t,vector<int>&temp,vector<vector<int>>&ans,vector<int>&candidates){

        if(t==0){
            ans.push_back(temp);
            return;
        }

        if(idx>=candidates.size() || t<0){
            return;
        }

        if(candidates[idx]<=t){
            temp.push_back(candidates[idx]);
            f(idx+1,t-candidates[idx],temp,ans,candidates);
            while(idx+1<candidates.size() && candidates[idx]==candidates[idx+1]){
                idx++;
            }
            temp.pop_back();
        }

        f(idx+1,t,temp,ans,candidates);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());

        vector<vector<int>>ans;
        vector<int>temp;

        f(0,target,temp,ans,candidates);

        return ans;


    }
};