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
    void f(vector<vector<int>>&ans,TreeNode* root,int target,vector<int>&temp){
        if(root==NULL){
            return;
        }
        //vector<int>temp;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(target==root->val)
                ans.push_back(temp);
        }
        f(ans,root->left,target-(root->val),temp);
      
        f(ans,root->right,target-(root->val),temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(ans,root,targetSum,temp);
        return ans;
    }
};