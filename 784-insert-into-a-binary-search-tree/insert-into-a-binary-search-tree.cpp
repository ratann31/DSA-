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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            return new TreeNode(val);
        }
        TreeNode* curr=root;
        while(curr){
            if(curr->val > val){
                //insert on left side is empty
                if(curr->left==NULL){
                    TreeNode* newNode=new TreeNode(val);
                    curr->left=newNode;
                    return root;
                }
                curr=curr->left;
            }else{
                //insert on right if empty
                if(curr->right==NULL){
                    TreeNode* newNode=new TreeNode(val);
                    curr->right=newNode;
                    return root;
                }
                curr=curr->right;
            }
        }
        return NULL;
    }
};