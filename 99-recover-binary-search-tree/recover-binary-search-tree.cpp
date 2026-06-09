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
    void f(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        f(root->left,v);
        v.push_back(root->val);
        f(root->right,v);
    }
    void inorder(int &idx,TreeNode* root,vector<int>&v){
        if(root==NULL)return;
        inorder(idx,root->left,v);
        root->val=v[idx];
        idx++;
        inorder(idx,root->right,v);
    }
    void recoverTree(TreeNode* root) {
        vector<int>v;
        f(root,v);
        sort(v.begin(),v.end());
        // for(auto &it:v){
        //     cout<<it<<" "<<endl;
        // }
        int idx=0;
        inorder(idx,root,v);
    }
};