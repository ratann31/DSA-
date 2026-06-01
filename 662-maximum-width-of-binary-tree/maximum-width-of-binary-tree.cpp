/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long mx=1;
        queue<pair<TreeNode*,int>>q;//{node,index}
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            long long minIdx=q.front().second;
            long long left=0,right=0;

            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();

                TreeNode* currNode=it.first;
                long long idx=it.second-minIdx;

                if(i==0){
                    left=idx;
                }
                if(i==sz-1){
                    right=idx;
                }
                if(currNode->left){
                    q.push({currNode->left,2*idx+1});
                }
                if(currNode->right){
                    q.push({currNode->right,2*idx+2});
                }
            }
            mx=max(mx,right-left+1);
        }
        return mx;
    }
};