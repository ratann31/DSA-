class Solution {
public:
    int MOD = 1e9 + 7;

    int m, n;

    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int rem,
              vector<vector<int>>& grid, int k) {

        if (i == m-1 && j == n-1) {
            return (rem == 0);
        }

        if (dp[i][j][rem] != -1) {
            return dp[i][j][rem];
        }

        int ans = 0;

        // Move Down
        if (i+1 < m) {
            int newRem = (rem + grid[i+1][j]) % k;

            ans = (ans + solve(i+1, j, newRem, grid, k)) % MOD;
        }

        // Move Right
        if (j+1 < n) {
            int newRem = (rem + grid[i][j+1]) % k;

            ans = (ans + solve(i, j+1, newRem, grid, k)) % MOD;
        }

        return dp[i][j][rem] = ans;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {

        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(k, -1)
        ));

        return solve(0, 0, grid[0][0] % k, grid, k);
    }
};