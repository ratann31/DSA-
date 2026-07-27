class Solution {
public:
    bool dfs(int node,unordered_map<int,vector<int>>&adj, vector<bool>&vis,vector<bool>&recStack){
        vis[node]=true;
        recStack[node]=true;

        for(auto &it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,recStack)){
                    return true;
                }
            }else if(recStack[it]){
                return true; 
            }
        }
        recStack[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
        int V=numCourses;

        unordered_map<int,vector<int>>adj;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[v].push_back(u);
        }

        vector<bool>vis(V,false);
        vector<bool>recStack(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,recStack)){ //cycle found
                    return false;
                }   
            }
        }

        return true;
    }
};