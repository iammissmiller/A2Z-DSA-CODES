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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> leftSt, rightSt;

        TreeNode* left = root;
        TreeNode* right = root;

        // Initialize inorder iterator
        while (left) {
            leftSt.push(left);
            left = left->left;
        }

        // Initialize reverse inorder iterator
        while (right) {
            rightSt.push(right);
            right = right->right;
        }

        while (!leftSt.empty() && !rightSt.empty()) {
            TreeNode* l = leftSt.top();
            TreeNode* r = rightSt.top();

            if (l == r)
                break;

            int sum = l->val + r->val;

            if (sum == k)
                return true;

            if (sum < k) {
                // Next larger value
                leftSt.pop();
                TreeNode* node = l->right;

                while (node) {
                    leftSt.push(node);
                    node = node->left;
                }
            } 
            else {
                // Next smaller value
                rightSt.pop();
                TreeNode* node = r->left;

                while (node) {
                    rightSt.push(node);
                    node = node->right;
                }
            }
        }

        return false;
    }
};
