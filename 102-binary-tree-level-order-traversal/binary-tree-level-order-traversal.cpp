class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)return {};

        queue<TreeNode*>q;
        q.push(root);

        vector<vector<int>>ans;

        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
            while(sz--){
                TreeNode* currNode=q.front();
                q.pop();

                temp.push_back(currNode->val);
                if(currNode->left){
                    q.push(currNode->left);
                }
                if(currNode->right){
                    q.push(currNode->right);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};