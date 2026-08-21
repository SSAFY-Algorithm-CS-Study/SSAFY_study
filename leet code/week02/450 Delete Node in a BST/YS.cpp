/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : BST                                     SS      WW   WW  */
/* Time Complexity   : O(h)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(h)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
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

// 삭제 노드가 맨 밑에있으면 nullptr
// 삭제노드 자식노드가 왼쪽만 있으면 왼쪽 노드
// 오른쪽만 있으면 오른쪽 노드
// 둘다있으면
// 오른쪽 노드중 제일 작은 노드 또는
// 왼쪽 노드중 제일 큰노드

// 오른쪽에서 제일 왼쪽에 있는 노드 값을 없애고 그 값을 현재 노드에


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)return nullptr; // 비어있으면 nullptr 반환
        if(root->val > key) root->left =  deleteNode(root->left, key); // key값보다 크면 왼쪽으로
        else if(root->val < key) root->right =  deleteNode(root->right, key); // key값보다 작으면 오른쪽으로
        else{ // key값 찾으면
            if(root->left == nullptr) return root->right; // 왼쪽이 비어있으면 right 반환
            if(root->right == nullptr) return root->left; // 오른쪽이 비어있으면 left 반환
            TreeNode* temp = root->right; // 자식노드가 둘다 있으면 오른쪽 노드중 제일 작은 값 찾고, 대체
            while(temp->left != nullptr){
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};


