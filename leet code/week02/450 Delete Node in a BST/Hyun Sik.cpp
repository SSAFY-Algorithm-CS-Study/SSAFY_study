/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 이진탐색트리                            SS      WW   WW  */
/* Time Complexity   : O(H) (h는 트리의 높이)                  SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              : leet : 767 Reorganize String            SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        // 입출력 속도 향상
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        TreeNode* parent = nullptr; // 삭제 대상 노드의 부모 노드
        TreeNode* current = root;   // 삭제 탐색용 현재 노드
                
        while (current != nullptr && current->val != key) // 삭제할 노드(current) 및 그 부모(parent) 탐색
        {
            parent = current; // 부모 설정
            if (key < current->val) // 현재 값이 찾을 key보다 크면 
            {
                current = current->left; // 현재 포인터를 왼쪽으로 이동(이유는 이진 탐색 트리는 
                                         // 왼쪽 루트 오른쪽으로 수가 커지므로)
            }
            else  // 현재 값이 찾을 key보다 작으면
            {
                current = current->right; // 현재 포인터를 오른쪽으로 이동
            }
        }

        if (current == nullptr) // key를 가진 노드가 트리에 없는 경우
        {
            return root; // 루트 리턴
        }

        if (current->left == nullptr || current->right == nullptr) // 삭제할 노드의 자식 개수에 따른 처리
        {                                                          // 자식이 0개이거나 1개만 있는 경우
            
            TreeNode* child = (current->left != nullptr) ? current->left : current->right; // 존재하는 자식을 선택 (둘 다 없으면 nullptr)

            if (parent == nullptr) // 삭제할 노드가 루트 노드인 경우
            {
                delete current; // 메모리 해제
                return child;   // 자식이 새로운 루트가 됨
            }
            
            if (parent->left == current) // 부모 노드의 왼쪽 노드가 현재 노드라면
            {
                parent->left = child; // 부모 노드의 왼쪽 포인터를 삭제할 노드의 자식으로 직접 연결
            }
            else
            {
                parent->right = child; // 반대면 오른쪽이 자식 노드
            }

            delete current; // 메모리 해제
        }        
        else //  자식 노드가 2개 모두 있는 경우 (포인터 재연결)
        {
            TreeNode* child = current->right; // 대체할 루트 서브트리 (오른쪽 자식)
                        
            TreeNode* temp = current->right; // 오른쪽 서브트리의 가장 왼쪽(최솟값) 노드를 찾음
            while (temp->left != nullptr) // 삭제할 노드의 오른쪽 노드의 왼쪽에 노드가 있다면
            {
                temp = temp->left; // 왼쪽 노드를 연결을 해줘야하기 때문에 temp 포인터를 왼쪽으로 
            }          
            
            temp->left = current->left;  // 최솟값 노드의 왼쪽에 기존 삭제 대상의 왼쪽 서브트리를 연결
                                         // (삭제 노드의 왼쪽 서브트리 전체는 최솟값 노드보다 항상 작으므로 BST 조건 만족)
            
            if (parent == nullptr) // 부모 노드가 널 포인터이면
            {
                root = child; // 부모 노드와 새로운 서브트리 루트(child) 연결
            }
            else if (parent->left == current) // 부모의 왼쪽 노드가 삭제할 노드면 
            {
                parent->left = child; // 그 자리에 자식 노드
            }
            else // 전부 아니면
            {
                parent->right = child; // 오른쪽에 자식노드
            }

            delete current; // 동적 할당 메모리 해제
        }

        return root; // 정답인 root 리턴
    }
};