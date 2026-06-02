class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        //making graph
        unordered_map<int,vector<int>>adj;
        queue<TreeNode*>pq;
        pq.push(root);
        while(!pq.empty()){
            TreeNode* currNode=pq.front();
            pq.pop();
            if(currNode->left){
                adj[currNode->val].push_back(currNode->left->val);
                adj[currNode->left->val].push_back(currNode->val);
                pq.push(currNode->left);
            }
            if(currNode->right){
                adj[currNode->val].push_back(currNode->right->val);
                adj[currNode->right->val].push_back(currNode->val);
                pq.push(currNode->right);
            }
        }
        //implementing bfs logic
        unordered_map<int,bool>vis;
        queue<int>q;
        q.push(target->val);
        vis[target->val]=true;
        int level=0;
        while(!q.empty()){
            int n=q.size();
             if(level == k){ // collect all nodes at this level
        while(n--){
            ans.push_back(q.front());
            q.pop();
        }
        break; // stop BFS after distance k
    }
            while(n--){
                int currNode=q.front();
                q.pop();
                for(auto &it:adj[currNode]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                    }
                    
                }
            }
            level++;

        }
        return ans;
    }
};