class Solution {
public:

    int solve(int idx,
              int m,
              int n,
              vector<pair<int,int>>& cnt,
              vector<vector<vector<int>>>& dp){

        // base case
        if(idx < 0){
            return 0;
        }

        // memoization
        if(dp[idx][m][n] != -1){
            return dp[idx][m][n];
        }

        int zero = cnt[idx].first;
        int one  = cnt[idx].second;

        // skip current string
        int skip = solve(idx - 1, m, n, cnt, dp);

        // pick current string
        int pick = 0;

        if(zero <= m && one <= n){
            pick = 1 + solve(idx - 1,
                             m - zero,
                             n - one,
                             cnt,
                             dp);
        }

        return dp[idx][m][n] = max(pick, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        int sz = strs.size();

        // precompute zeros and ones
        vector<pair<int,int>> cnt;

        for(string &s : strs){

            int zero = 0;
            int one = 0;

            for(char ch : s){

                if(ch == '0'){
                    zero++;
                }
                else{
                    one++;
                }
            }

            cnt.push_back({zero, one});
        }

        // 3D DP
        vector<vector<vector<int>>> dp(
            sz,
            vector<vector<int>>(m + 1,
            vector<int>(n + 1, -1))
        );

        return solve(sz - 1, m, n, cnt, dp);
    }
};