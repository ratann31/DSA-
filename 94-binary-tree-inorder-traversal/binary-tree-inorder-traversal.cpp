class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // If no left child, visit this node
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find inorder predecessor
                TreeNode* IP = curr->left;
                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }

                if (IP->right == NULL) {
                    // Make thread
                    IP->right = curr;
                    curr = curr->left;   // ✅ go left
                } else {
                    // Thread already exists → remove it and visit node
                    IP->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};
