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
    int btoD(string s){
        int result=0;
        for(char ch:s){
            result=result*2+(ch-'0');
        }
        return result;
    }
    void f(TreeNode* root,string &temp,vector<string>&v){
        if(root==NULL)return;
        temp+=root->val+'0';
        //if leaf node
        if(root->left==NULL && root->right==NULL){
            v.push_back(temp);
            temp.pop_back();
            return;
        }
        //explore left and right
        f(root->left,temp,v);
        f(root->right,temp,v);
        //pop last
        temp.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string>v;
        string temp="";
        f(root,temp,v);
        for(auto &it:v){
            cout<<it<<" ";
        }
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=btoD(v[i]);
        }   
        return sum;
    }
};