class Solution {
public:
    void inorder(TreeNode* root,map<TreeNode*,TreeNode*>&parent){
        if(root==NULL)return;
        if(root->left!=NULL){
            parent[root->left]=root;
        }
        inorder(root->left,parent);
        if(root->right!=NULL){
            parent[root->right]=root;
        }
        inorder(root->right,parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        map<TreeNode*,TreeNode*>parent;
        map<TreeNode*,bool>visited;
        inorder(root,parent);
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
            while(sz--){
                TreeNode* currNode=q.front();
                visited[currNode]=true;
                q.pop();
                if(currNode->left && !visited[currNode->left]){
                    visited[currNode->left]=true;
                    q.push(currNode->left);
                }
                if(currNode->right && !visited[currNode->right]){
                    visited[currNode->right]=true;
                    q.push(currNode->right);
                }
                if(parent.find(currNode)!=parent.end() && !visited[parent[currNode]]){
                    visited[parent[currNode]]=true;
                    q.push(parent[currNode]);
                }
                temp.push_back(currNode->val);
            }
            if(level==k)return temp;
            level++;
        }
        return {};

    }
};