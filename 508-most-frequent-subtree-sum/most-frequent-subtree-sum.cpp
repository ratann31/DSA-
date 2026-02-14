class Solution {
public:
    int f(TreeNode* root,unordered_map<TreeNode*,int>&mpp){
        if(root==NULL){
            return 0;
        }
        int sum=root->val+f(root->left,mpp)+f(root->right,mpp);
        mpp[root]=sum;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        unordered_map<TreeNode*,int>mpp;//{root,sum Val}
        f(root,mpp);
        for(auto &it:mpp){
            ans.push_back(it.second);
        }
        unordered_map<int,int>mp;//{sum Val,freq}
        for(int i=0;i<ans.size();i++){
            mp[ans[i]]++;
        }
        //find highest freq
        int mx=-1;
        for(auto &it:mp){
            if(it.second>mx){
                mx=it.second;
            }
        }
        //push all elements of highest freq into the result
        set<int>st;
        for(int i=0;i<ans.size();i++){
            if(mp[ans[i]]==mx){
                st.insert(ans[i]);
            }
        }
        vector<int>result;
        for(auto &it:st){
            result.push_back(it);
        }
        return result;
    }
};