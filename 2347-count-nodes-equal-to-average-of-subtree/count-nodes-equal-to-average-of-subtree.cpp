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
    int cnt=0;
    unordered_map<TreeNode*,pair<int,int>>mpp;//{node,avgValue}
    void dfs(TreeNode* root){
        if(root==NULL)return;

        dfs(root->left);
        dfs(root->right);
        
        if(root->left==NULL && root->right==NULL){
            mpp[root]={1,root->val};
            return;
        }
        int leftVal=0;
        int rightVal=0;

        if(root->left){
            leftVal=mpp[root->left].second;
        }
        if(root->right){
            rightVal=mpp[root->right].second;
        }
        int total = leftVal+rightVal+root->val;

        int n1=0;
        int n2=0;

        if(root->left){
            n1=mpp[root->left].first;
        }
        if(root->right){
            n2=mpp[root->right].first;
        }
        int n=1+n1+n2;

        mpp[root]={n,total};

       

    }
    void inorder(TreeNode* root){
        if(root==NULL)return;

        inorder(root->left);
        int sum=mpp[root].second;
        int n=mpp[root].first;

        if(sum/n == root->val){
            cnt++;
        }
        inorder(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        inorder(root);

        return cnt;
    }
};