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
    void f(TreeNode* root,int k,vector<int>&inorder){
        if(root==NULL){
            return;
        }
        f(root->left,k,inorder);
        inorder.push_back(root->val);
        f(root->right,k,inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        f(root,k,inorder);
        return inorder[k-1];
    }
};