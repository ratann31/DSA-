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
    void inorder(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mpp,int &sum){
        if(root==NULL)return;
        inorder(root->left,mpp,sum);

        if(mpp.find(root)!=mpp.end()){
            TreeNode* parent=mpp[root];
            if(mpp.find(parent)!=mpp.end()){
                TreeNode* grandParent=mpp[parent];

                if(grandParent->val % 2== 0){
                    sum+=root->val;
                }
            }
        }

        inorder(root->right,mpp,sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        unordered_map<TreeNode*,TreeNode*>mpp; // { node , patentNode}
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                TreeNode* currNode=q.front();
                q.pop();

                if(currNode->left){
                    mpp[currNode->left]=currNode;
                    q.push(currNode->left);
                }
                if(currNode->right){
                    mpp[currNode->right]=currNode;
                    q.push(currNode->right);
                }
            }
        }

        int sum=0;
        inorder(root,mpp,sum);
        return sum;
    }
};