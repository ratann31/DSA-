class Solution {
public:
    TreeNode* helper(vector<int>&preorder,int rootindex,int right){
        if(rootindex>=right) return nullptr;

        int value = preorder[rootindex];
        TreeNode* root=new TreeNode(value);

        int i=rootindex+1;
        while(i<=preorder.size()-1 && preorder[i]<value){
            i++;
        }

        root->left=helper(preorder,rootindex+1,i);
        root->right=helper(preorder,i,right);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size());
    }
};