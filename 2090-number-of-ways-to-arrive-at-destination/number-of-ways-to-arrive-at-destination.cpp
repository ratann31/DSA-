class Solution {
public:
    int mod=1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
    
        unordered_map<long long,vector<pair<long long,long long>>>adj;
        for(int i=0;i<roads.size();i++){
            long long u=roads[i][0];
            long long v=roads[i][1];
            long long time=roads[i][2];

           adj[u].push_back({v,time});
           adj[v].push_back({u,time});
        }

        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;//{dist,node}
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            long long currDist=it.first;
            long long currNode=it.second;

            pq.pop();

            //iterate in the adjacent nodes
            for(auto &it:adj[currNode]){
                long long adjNode=it.first;
                long long edWt=it.second;

                if(currDist+edWt<dist[adjNode]){
                    dist[adjNode]=currDist+edWt;
                    pq.push({currDist+edWt,adjNode});

                    ways[adjNode]=ways[currNode];
                }else if(currDist+edWt==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[currNode])%mod;
                }
            }
           
        }
        return ways[n-1]%mod;
    }
};