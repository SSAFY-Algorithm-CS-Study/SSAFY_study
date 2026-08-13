/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 이진트리 탐색                           SS      WW   WW  */
/* Time Complexity   : O(h) : 이진트리 depth                   SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* temp = root;

        while(temp != NULL){
            //현재 노드의 값이 p,q 값 사이에 있으면 두 노드가 갈라지는 지점이므로 LCA임
            if((temp->val >= p->val && temp->val <= q->val) || (temp->val <= p->val && temp->val >= q->val))
                return temp;
            
            // p,q가 모두 현재 노드 값보다 작으면 왼쪽으로 이동 후 탐색
            else if(temp->val > p->val && temp->val > q->val)
                temp = temp->left;
            
            // p,q가 모두 현재 노드 값보다 크면 오른쪽으로 이동 후 탐색
            else if(temp->val < p->val && temp->val < q->val)
                temp = temp->right;
        }
        
        return NULL;
    }
};

/*
int main(void)
{
    Solution sol;

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);


    TreeNode* p = root->left;
    TreeNode* q = root->right;
    TreeNode* q2 = root->left->right;
    
    TreeNode* answer = sol.lowestCommonAncestor(root, p ,q);
    TreeNode* answer2 = sol.lowestCommonAncestor(root, p ,q2);

    cout << answer->val << ' ' << answer2->val;

}
*/