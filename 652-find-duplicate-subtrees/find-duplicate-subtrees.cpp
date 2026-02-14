class Solution {
public:
    string getSubString(TreeNode* root,unordered_map<string,int>&mpp,vector<TreeNode*>&result){
        if(root==NULL){
            return "N";
        }
        string s=to_string(root->val)+","+getSubString(root->left,mpp,result)+","+getSubString(root->right,mpp,result);
        if(mpp[s]==1){
            result.push_back(root);
        }
        mpp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mpp;
        vector<TreeNode*>result;
        getSubString(root,mpp,result);
        return result; 
    }
};