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
    long long totalSum=0;
    long long ans=0;

    long long dfs(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        long long left=dfs(node->left);
        long long right=dfs(node->right);

        long long currSum=left+right+node->val;

        ans=max(ans,currSum*(totalSum-currSum));

        return currSum;
    }
    int maxProduct(TreeNode* root) {
        totalSum=dfs(root);
        dfs(root);
         return ans % 1000000007;
    }
};