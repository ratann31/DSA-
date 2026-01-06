class Solution {
public:
   void solve(int idx, int k, vector<int>& temp,
           vector<vector<int>>& ans, vector<int>& digit) {

    if (temp.size() == k) {
        ans.push_back(temp);
        return;
    }

    if (idx >= digit.size()) return;

    // pick
    temp.push_back(digit[idx]);
    solve(idx + 1, k, temp, ans, digit);
    temp.pop_back();

    // not pick
    solve(idx + 1, k, temp, ans, digit); 
}

    vector<vector<int>> combine(int n, int k) {
        vector<int>digit;
        for(int i=1;i<=n;i++){
            digit.push_back(i);
        }
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,k,temp,ans,digit);
        return ans;
    }
};