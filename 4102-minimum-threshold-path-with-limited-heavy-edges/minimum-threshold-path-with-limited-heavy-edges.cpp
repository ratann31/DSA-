#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minimumThreshold(
        int n,
        vector<vector<int>>& edges,
        int source,
        int target,
        int k
    ) {

        vector<vector<pair<int,int>>> adj(n);

        int hi = 0;

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});

            hi = max(hi, wt);
        }

        int lo = 0;

        int ans = -1;

        auto possible = [&](int threshold) {

            deque<int> dq;

            vector<int> dist(n, 1e9);

            dist[source] = 0;

            dq.push_front(source);

            while (!dq.empty()) {

                int node = dq.front();
                dq.pop_front();

                for (auto &it : adj[node]) {

                    int next = it.first;
                    int wt = it.second;

                    int cost = (wt > threshold);

                    if (dist[node] + cost < dist[next]) {

                        dist[next] = dist[node] + cost;

                        if (cost == 0) {
                            dq.push_front(next);
                        }
                        else {
                            dq.push_back(next);
                        }
                    }
                }
            }

            return dist[target] <= k;
        };

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (possible(mid)) {

                ans = mid;

                hi = mid - 1;
            }
            else {

                lo = mid + 1;
            }
        }

        return ans;
    }
};