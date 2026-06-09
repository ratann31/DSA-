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
    bool ans=false;
    void solve(TreeNode* root,int k,unordered_map<int,int>&mpp){
        if(root==NULL)return;
        solve(root->left,k,mpp);
        int rem=k-root->val;
        if(mpp.find(rem)!=mpp.end()){
            ans=true;
            return;
        }else{
            mpp[root->val]=1;
        }
        solve(root->right,k,mpp);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mpp;
        solve(root,k,mpp);
        return ans;
    }
};