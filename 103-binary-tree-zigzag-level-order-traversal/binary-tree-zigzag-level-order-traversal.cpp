class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>>ans;

        queue<TreeNode*>q;
        q.push(root);

        bool leftToRight=true;

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

            if(leftToRight){
                ans.push_back(temp);
               
            }else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            leftToRight=!leftToRight;
        }

        return ans;
    }
};