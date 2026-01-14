class Solution {
public:
    void bfs(int src, unordered_map<int,vector<int>>adj,vector<int>&vis){
        queue<int>q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int currNode=q.front();
            q.pop();
            for(auto &it:adj[currNode]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<V;i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int>vis(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                cnt++;
                bfs(i,adj,vis);
            }
        }
        return cnt;
    }
};