class Solution {
public:
    int postIndex;
    unordered_map<int,int> pos;

    TreeNode* build(vector<int>& postorder,
                    int inStart,
                    int inEnd) {

        if(inStart > inEnd)
            return NULL;

        int rootVal = postorder[postIndex--];

        TreeNode* root =
            new TreeNode(rootVal);

        int idx = pos[rootVal];

        root->right =
            build(postorder,
                  idx + 1,
                  inEnd);

        root->left =
            build(postorder,
                  inStart,
                  idx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        int n = inorder.size();

        postIndex = n - 1;

        for(int i = 0; i < n; i++)
            pos[inorder[i]] = i;

        return build(postorder, 0, n - 1);
    }
};