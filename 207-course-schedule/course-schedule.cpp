class Solution {
public:
    bool dfs(int currNode,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathVis){
        vis[currNode]=1;
        pathVis[currNode]=1;

        for(auto &it:adj[currNode]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis)==true){
                    return true;
                }
            }
            else if(vis[it]==1 && pathVis[it]==1){
                return true;
            }
        }
        pathVis[currNode]=0;
        return false;
    }

    bool checkCycle(vector<vector<int>>&adj,int V){
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathVis)==true)return true;
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        return !(checkCycle(adj,numCourses));
    }
};