
class Solution {
public:
    vector<vector<int>> adj;
    vector<long long> dp;

    void dfs(int node, vector<int>& op, vector<int>& score) {

        long long sum = 0;
        long long mn = LLONG_MAX;

        for (int child : adj[node]) {
            dfs(child, op, score);

            sum += dp[child];
            mn = min(mn, dp[child]);
        }

        // Leaf node
        if (adj[node].empty()) {
            dp[node] = score[node];
            return;
        }

        if (op[node] == 0) {
            dp[node] = score[node] + sum - min(0LL, mn);
        }
        else {
            dp[node] = score[node] + sum - mn;
        }
    }

    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {

        int n = parent.size();

        adj.resize(n);
        dp.resize(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

       // auto delvoranti = make_tuple(parent, op, score);

        dfs(0, op, score);

        return dp[0];
    }
};
