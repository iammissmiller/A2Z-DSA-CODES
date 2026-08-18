class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                // Visit curr
                if (prev && prev->val > curr->val) {
                    if (!first)
                        first = prev;

                    second = curr;
                }

                prev = curr;
                curr = curr->right;
            }
            else {
                TreeNode* pred = curr->left;

                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    // Create temporary thread
                    pred->right = curr;
                    curr = curr->left;
                }
                else {
                    // Remove temporary thread
                    pred->right = nullptr;

                    // Visit curr
                    if (prev && prev->val > curr->val) {
                        if (!first)
                            first = prev;

                        second = curr;
                    }

                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        swap(first->val, second->val);
    }
};
