
class Solution {
public:
    void f(TreeNode* root,map<int,map<int,multiset<int>>>&mpp,int col,int row){
        if(root==NULL){
            return;
        }
        mpp[col][row].insert(root->val);
        f(root->left,mpp,col-1,row+1);
        f(root->right,mpp,col+1,row+1);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>mpp;
        f(root,mpp,0,0);
        for(auto &colPair:mpp){
            vector<int>temp;
            for(auto &rowPair:colPair.second){
                for(auto val:rowPair.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        } 
        return ans;
    }
};