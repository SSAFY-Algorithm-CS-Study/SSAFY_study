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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)return nullptr;
        if(root->val > key) root->left =  deleteNode(root->left, key);
        else if(root->val < key) root->right =  deleteNode(root->right, key);
        else{
            if(root->left == nullptr) return root->right;
            if(root->right == nullptr) return root->left;
            TreeNode* temp = root->right;
            while(temp->left != nullptr){
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};

// 삭제 노드가 맨 밑에있으면 그냥 nullptr
// 삭제노드 자식노드가 왼쪽만 있으면 바로 왼쪽 노드
// 오른쪽만 있으면 오른쪽 노드
// 둘다있으면
// 오른쪽 노드중 제일 작은 노드? 
// 왼쪽 노드중 제일 큰노드?

// 오른쪽에서 제일 왼쪽에 있는 노드로 바꾸고 이 노드는 NULLPTR 

