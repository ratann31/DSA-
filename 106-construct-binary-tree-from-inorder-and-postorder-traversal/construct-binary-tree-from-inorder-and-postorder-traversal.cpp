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
    TreeNode* f(vector<int>& inorder, vector<int>& postorder,int start,int end,int &idx){
        if(start>end){
            return NULL;
        }
        int rootVal=postorder[idx];
        int ix;
        for(int i=start;i<=end;i++){
            if(inorder[i]==rootVal){
                ix=i;
                break;
            }
        }
        idx++;
        TreeNode* root=new TreeNode(rootVal);
       
        root->right=f(inorder,postorder,ix+1,end,idx);
        root->left=f(inorder,postorder,start,ix-1,idx);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        reverse(postorder.begin(),postorder.end());
        int idx=0;
        return f(inorder,postorder,0,n-1,idx);
    }
};