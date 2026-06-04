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
    int preIdx=0;
    unordered_map<int,int>pos;
    TreeNode* build(vector<int>&preorder,int inStart,int inEnd){
        if(inStart>inEnd){
            return NULL;
        }
        int rootVal=preorder[preIdx];
        preIdx++;
        TreeNode* root= new TreeNode(rootVal);
        //find inorder index for splitting
        int idx=pos[rootVal];
        root->left=build(preorder,inStart,idx-1);
        root->right=build(preorder,idx+1,inEnd);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            pos[inorder[i]]=i;
        }
        return build(preorder,0,inorder.size()-1);
    }
};