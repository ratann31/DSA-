
class Solution {
public: 
    TreeNode* f(vector<int>& preorder, vector<int>& inorder,int start,int end,int&idx){
        if(start>end){
            return NULL;    
        }
        int rootVal=preorder[idx];
        int i_val;
        for(int i=start;i<end;i++){
            if(inorder[i]==rootVal){
                i_val=i;
                break;
            }
        }
        idx++;
        TreeNode* root=new TreeNode(rootVal);
        root->left=f(preorder,inorder,start,i_val-1,idx);
        root->right=f(preorder,inorder,i_val+1,end,idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int idx=0;
        return f(preorder,inorder,0,n-1,idx);
    }
};