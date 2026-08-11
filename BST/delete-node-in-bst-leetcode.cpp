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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;

        TreeNode* parent = nullptr;
        TreeNode* curr = root;

        // Find the node to delete
        while (curr && curr->val != key) {
            parent = curr;

            if (key < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (!curr)
            return root;

        // Case 1: Node has two children
        if (curr->left && curr->right) {
            TreeNode* successorParent = curr;
            TreeNode* successor = curr->right;

            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }

            curr->val = successor->val;

            parent = successorParent;
            curr = successor;
        }

        // Now curr has at most one child
        TreeNode* child = curr->left ? curr->left : curr->right;

        // Deleting root
        if (!parent)
            return child;

        // Connect parent to child
        if (parent->left == curr)
            parent->left = child;
        else
            parent->right = child;

        delete curr;

        return root;
    }
};
