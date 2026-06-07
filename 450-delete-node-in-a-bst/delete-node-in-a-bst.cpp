class Solution {
public:
    int findMax(TreeNode* root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;

        if(root->val < key){
            root->right=deleteNode(root->right,key);
        }else if(root->val > key){
            root->left=deleteNode(root->left,key);
        }else{
            if(root->left!=NULL && root->right!=NULL){
                int mx=findMax(root->left);
                root->val=mx;
                root->left=deleteNode(root->left,mx);
                return root;
            }else if(root->left!=NULL){
                return root->left;
            }else if(root->right!=NULL){
                return root->right;
            }else{
                return NULL;
            }
        }
        return root;
    }
};