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
    bool check(TreeNode* root,long long minVal,long long maxVal){
        //base case
        if(root==NULL){
            return true;
        }
        //check
        if(root->val <=minVal || root->val >=maxVal){
            return false;   
        }
        //check left
        bool left_check=check(root->left,minVal,root->val);
        //check right
        bool right_check=check(root->right,root->val,maxVal);

        return left_check && right_check;
    }
    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};