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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        ll ans=1;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        while(!q.empty()){
            ll sz=q.size();
            ll start=q.front().second;
            ll end=q.back().second;
            ans=max(ans,end-start+1);
            while(sz--){
                auto it=q.front();
                q.pop();
                TreeNode* currNode=it.first;
                ll idx=it.second;
                if(currNode->left){
                    q.push({currNode->left,2*idx+1});
                }
                if(currNode->right){
                    q.push({currNode->right,2*idx+2});
                }
            }
           
        }
        return (int)ans;
    }
};