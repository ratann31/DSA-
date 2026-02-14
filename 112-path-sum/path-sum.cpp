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
    bool f(TreeNode* root,int target){
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            return target==root->val;
        }
        bool left=f(root->left,target-(root->val));
        bool right=f(root->right,target-(root->val));
        return left|| right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return f(root,targetSum);
    }
};