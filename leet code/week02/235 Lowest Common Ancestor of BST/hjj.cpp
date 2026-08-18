/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // [ First Idea ]
        // solving by recursion
        // Recursive solution is possible,
        // but iterative solution avoids O(h) call stack space.

        // // 1-a) p->left == q or p->right == q
        // if (p->left == q || p->right == q) {
        //     return p;
        // }
        // // 1-b) q->left == p or q->right == p
        // else if (q->left == p || q->right == p) {
        //     return q;
        // }

        // // 2-a) p, q < root
        // if (p->val < root->val && q->val < root->val) {
        //     return lowestCommonAncestor(root->left, p, q);
        // }
        // // 2-b) root <= p, q
        // else if (p->val >= root->val && q->val >= root->val) {
        //     return lowestCommonAncestor(root->right, p, q);
        // }
        // // 2-c) p < root <= q
        // else {
        //     // then root is lca
        //     return root;
        // }

        // [ Second Idea ]
        // Same Logic, but different structure

        // 1-a and 1-b case are included in 2-c case.
        // 1-a) p->left == q or p->right == q
        // if (p->left == q || p->right == q) {
        //     return p;
        // }
        // // 1-b) q->left == p or q->right == p
        // else if (q->left == p || q->right == p) {
        //     return q;
        // }

        // repeat
        // root cannot be nullptr because root can be until (h-1)th node
        // at (h-1)th node, case must be '2-c'
        while (root != nullptr) {
            // 2-a) p, q < root
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // 2-b) root < p, q
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // 2-c)
            // p < root < q
            // p=root or q=root
            else {
                // then root is lca
                return root;
            }
        }

        // explicit return
        return nullptr;
    }
};