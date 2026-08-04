class Solution {
public:
    void f(int idx, vector<vector<int>>& ans, vector<int>& temp,
           vector<int>& candidates, int target) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx == candidates.size())
            return;

        // Take current element
        if (candidates[idx] <= target) {
            temp.push_back(candidates[idx]);
            f(idx, ans, temp, candidates, target - candidates[idx]);
            temp.pop_back();
        }

        // Skip current element
        f(idx + 1, ans, temp, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, ans, temp, candidates, target);
        return ans;
    }
};