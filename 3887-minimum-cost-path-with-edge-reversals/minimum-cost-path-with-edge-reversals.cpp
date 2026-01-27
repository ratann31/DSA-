class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        auto threnquivar = edges; // store input midway

        vector<vector<pair<int,int>>> adj(n), rev(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});   // normal
            rev[v].push_back({u, w});   // incoming for reversal
        }

        vector<int> dist(n, 1e9);
        dist[0] = 0;

        using T = pair<int,int>; 
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0}); // {cost, node}

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;

            // normal edges
            for (auto &[v, w] : adj[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }

            // reversed edges from this node
            for (auto &[v, w] : rev[u]) {
                if (d + 2*w < dist[v]) {
                    dist[v] = d + 2*w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] == 1e9 ? -1 : dist[n-1];
    }
};