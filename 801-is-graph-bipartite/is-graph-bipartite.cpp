class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int currNode,vector<int>&color,int currColor){
       color[currNode]=currColor;

       for(auto &it:graph[currNode]){
        if(color[it]==currColor){
            return false;
        }
        if(color[it]==-1){
            int colorOfit= 1-currColor;
            if(dfs(graph,it,color,colorOfit)==false){
                return false;
            }
        }
       }
       return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(graph,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};