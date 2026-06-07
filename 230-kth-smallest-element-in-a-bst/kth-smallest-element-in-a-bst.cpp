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
    void inorder(TreeNode* root,vector<int>&t){
        if(root==NULL)return;
        inorder(root->left,t);
        t.push_back(root->val);
        inorder(root->right,t);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>t;
        inorder(root,t);
        return t[k-1];
    }
};