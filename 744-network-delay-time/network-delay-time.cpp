class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int time=times[i][2];

            adj[u].push_back({v,time});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//{dist,node}
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        dist[0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            int currNode=it.second;
            int currDist=it.first;
            pq.pop();

            for(auto &it:adj[currNode]){
                int adjNode=it.first;
                int adjDist=it.second;

                if(currDist+adjDist<dist[adjNode]){
                    dist[adjNode]=currDist+adjDist;
                    pq.push({currDist+adjDist,adjNode});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
        }
        return *max_element(dist.begin()+1,dist.end());
    }
};