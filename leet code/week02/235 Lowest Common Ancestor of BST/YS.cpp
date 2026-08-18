/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : BST                                     SS      WW   WW  */
/* Time Complexity   : O(N) 노드 수                            SSSSS   WW W WW  */
/* Space Complexity  : O(H) 트리 높이                             SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
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
        if(root == p || root == q){
            return root; // 현재 root가 p 또는 q와 같으면 root 리턴
        }
        if(root == nullptr)return nullptr; // 더 탐색할 노드가 없으면 nullptr 리턴

        // 왼쪽 서브 트리에서 p또는 q를 찾음
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        // 오른쪽 서브 트리에서 p또는 q를 찾음
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left!=nullptr&&right!=nullptr)return root; //left, right가 p, q이면 root 리턴
        if(left !=nullptr)return left; // left에서만 찾았으면 그 노드를 위로 전달
        return right; //right에서만 찾았으면 right qksghks

    }
};