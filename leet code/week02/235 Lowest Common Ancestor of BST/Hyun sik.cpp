/********************************************************************************/
/* File Name         : Hyun sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 이진 탐색 트리(최소 공통 조상)          SS      WW   WW  */
/* Time Complexity   : O(h) (h-트리 높이)                      SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              : leet : 235 Lowest Common Ancestor of…   SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <cstddef>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        TreeNode* current = root; // 현재 노드(부모, 조상 노드)

        while (current != nullptr) // null 포인터가 아니면 반복문 실행
        {
            if (p->val < current->val && q->val < current->val) // 둘 다 왼쪽에 있으면 -> 왼쪽으로 이동(curr->left)
            {
                current = current->left;
            }            
            else if (p->val > current->val && q->val > current->val) // 둘 다 오른쪽에 있으면 -> 오른쪽으로 이동(curr->right)
            {
                current = current->right;
            }
            // 3. !
            else
            {
                return current; // 왼쪽 오른쪽으로 갈라졌거나 내가 목표물(문제 조건에 내가 조상 되는 것 가능) 중 하나라면 -> 노드 리턴
            }
        }
        
        return nullptr; // 안 나오면 리턴은 반드시 해야하므로 null 포인터 리턴
    }
};