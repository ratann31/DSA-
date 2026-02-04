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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //edge cases before starting
        if((p==NULL && q!=NULL)||(p!=NULL && q==NULL)){
            return false;
        }else if(p==NULL && q==NULL){
            return true;
        }
        queue<TreeNode*>q1,q2;
        q1.push(p),q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* node1=q1.front();
            TreeNode* node2=q2.front();

            q1.pop();
            q2.pop();

            if(node1->val!=node2->val)return false;
            //left condition
            if(node1->left!=NULL && node2->left!=NULL){
                q1.push(node1->left);
                q2.push(node2->left);
            }else if((node1->left!=NULL && node2->left==NULL)||
            (node1->left==NULL && node2->left!=NULL)){
                return false;
            }
            //right condition
            if(node1->right!=NULL && node2->right!=NULL){
                q1.push(node1->right);
                q2.push(node2->right);
            }else if((node1->right!=NULL && node2->right==NULL)||
            (node1->right==NULL && node2->right!=NULL)){
                return false;
            }
            
        }
        if((!q1.empty()&& q2.empty())||(!q2.empty() && q1.empty())){
            return false;
        }
        return true;
    }
};