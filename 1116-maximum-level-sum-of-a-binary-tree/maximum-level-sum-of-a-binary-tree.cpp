class Solution {
public:
    void dfs(TreeNode* root,int level,map<int,int>&mpp){
        if(root==NULL){
            return;
        }
        mpp[level]+=root->val;
        dfs(root->left,level+1,mpp);
        dfs(root->right,level+1,mpp);
    }
    int maxLevelSum(TreeNode* root) {
        map<int,int>mpp; //{level,sum}
        dfs(root,1,mpp);
        int mx=INT_MIN;
        int ans=0;
        for(auto &it:mpp){
            if(it.second>mx){
                mx=it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};