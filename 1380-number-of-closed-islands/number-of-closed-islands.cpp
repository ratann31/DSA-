
class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int row, int col,
             vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                grid[nr][nc] == 0 &&
                !vis[nr][nc]) {

                dfs(nr, nc, grid, vis);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Step 1: Mark all land connected to the boundary.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if ((i == 0 || j == 0 ||
                     i == n - 1 || j == m - 1) &&
                    grid[i][j] == 0 &&
                    !vis[i][j]) {

                    dfs(i, j, grid, vis);
                }
            }
        }

        // Step 2: Count the remaining islands.
        int total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0 && !vis[i][j]) {
                    dfs(i, j, grid, vis);
                    total++;
                }
            }
        }

        return total;
    }
};
