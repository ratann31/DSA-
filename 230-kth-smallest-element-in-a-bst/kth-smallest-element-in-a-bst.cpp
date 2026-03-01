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
    int f(TreeNode* root,int k,int &cnt){
        if(root==NULL){
            return -1;
        }
        if(root->left){
            int leftAns=f(root->left,k,cnt);
            if(leftAns!=-1){
                return leftAns;
            }
        }
        if(cnt==k){
            return root->val;
        }
        cnt++;
        if(root->right){
            int rightAns=f(root->right,k,cnt);
            if(rightAns!=-1){
                return rightAns;
            }
        }
        return -1;

    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=1;
        return f(root,k,cnt);
    }
};