#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {

        // graph[node] = {nextNode, normalCost, taxiMultiplier}
        vector<vector<vector<int>>> graph(n);

        for (auto &r : roads) {
            int u = r[0];
            int v = r[1];
            int cost = r[2];
            int taxi = r[3];

            graph[u].push_back({v, cost, taxi});
            graph[v].push_back({u, cost, taxi});
        }

        vector<int> ans(n);

        // Try for every starting shop
        for (int start = 0; start < n; start++) {

            // -------------------------------
            // 1. Shortest distance going empty
            // -------------------------------
            vector<ll> emptyDist(n, INF);

            priority_queue<
                pair<ll,int>,
                vector<pair<ll,int>>,
                greater<pair<ll,int>>
            > pq;

            emptyDist[start] = 0;
            pq.push({0, start});

            while (!pq.empty()) {

                auto [dist, node] = pq.top();
                pq.pop();

                if (dist > emptyDist[node])
                    continue;

                for (auto &edge : graph[node]) {

                    int next = edge[0];
                    int cost = edge[1];

                    if (emptyDist[next] > dist + cost) {

                        emptyDist[next] = dist + cost;

                        pq.push({emptyDist[next], next});
                    }
                }
            }

            // ---------------------------------
            // 2. Shortest distance carrying apple
            // ---------------------------------
            vector<ll> carryDist(n, INF);

            carryDist[start] = 0;

            pq.push({0, start});

            while (!pq.empty()) {

                auto [dist, node] = pq.top();
                pq.pop();

                if (dist > carryDist[node])
                    continue;

                for (auto &edge : graph[node]) {

                    int next = edge[0];
                    int cost = edge[1];
                    int taxi = edge[2];

                    ll newCost = dist + 1LL * cost * taxi;

                    if (carryDist[next] > newCost) {

                        carryDist[next] = newCost;

                        pq.push({newCost, next});
                    }
                }
            }

            // ---------------------------------
            // 3. Try buying apples from every shop
            // ---------------------------------

            ll best = prices[start];

            for (int shop = 0; shop < n; shop++) {

                ll total =
                    emptyDist[shop]
                    + prices[shop]
                    + carryDist[shop];

                best = min(best, total);
            }

            ans[start] = best;
        }

        return ans;
    }
};