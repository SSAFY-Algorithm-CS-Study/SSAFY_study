/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 현재 노드 초기화
        TreeNode* currNode = root;
        // 부모 노드 정의
        TreeNode* currParentNode = nullptr;

        // 비어있는 트리인 경우
        if (root == nullptr) {
            return root;
        }

        while (currNode != nullptr) {
            // 현재 노드가 삭제 대상인 경우
            if (key == currNode->val) {
                // 1. 어떠한 자식 노드도 없는 경우 바로 삭제
                if (currNode->left == nullptr && currNode->right == nullptr) {
                    // 삭제하려는 노드가 root인 경우
                    if (currParentNode == nullptr) {
                        root = nullptr;
                    }
                    // 부모 노드가 존재하는 경우 연결 해제
                    if (currParentNode != nullptr) {
                        if (currParentNode->left == currNode) {
                            currParentNode->left = nullptr;
                        }
                        else {
                            currParentNode->right = nullptr;
                        }
                    }
                    // 대상 노드 삭제
                    delete currNode;
                    return root;
                }

                // 2. 현재 노드가 한 쪽 방향의 노드만 있는 경우
                else if (currNode->right == nullptr || currNode->left == nullptr) {
                    // 자식 노드
                    TreeNode* childNode = (currNode->right != nullptr) ? currNode->right : currNode->left;

                    // 삭제하려는 노드가 root인 경우
                    if (currParentNode == nullptr) {
                        root = childNode;
                    }
                    // 부모 노드가 존재하는 경우, 연결 재정의
                    if (currParentNode != nullptr) {
                        if (currParentNode->left == currNode) {
                            currParentNode->left = childNode;
                        }
                        else {
                            currParentNode->right = childNode;
                        }
                    }
                    // 대상 노드 삭제
                    delete currNode;
                    return root;
                }

                // 3. 현재 노드가 모든 방향의 노드가 있는 경우
                else {
                    // 방법이 2가지 있음
                    // A. 왼쪽 서브트리의 최댓값으로 대체
                    // B. 오른쪽 서브트리의 최솟값으로 대체
                    // 현재 코드에선 A 방식은 주석 처리

                    /*
                    // a. 서브트리 탐색(해당 서브트리 안에서 최댓값 탐색)
                    // 왼쪽 서브트리 중 최댓값 노드
                    // 왼쪽 서브트리의 최상단 노드부터 시작
                    TreeNode* leftSubTreeMaxNode = currNode->left;
                    // leftSubTreeMaxNode의 부모 노드를 저장하기 위함
                    TreeNode* leftSubTreeMaxParentNode = currNode;

                    // 서브트리 탐색 (탐색이 끝나면 반복문 종료)
                    // 종료할 때 자연스럽게 왼쪽 서브트리 중 최댓값 노드가 됨
                    while (leftSubTreeMaxNode->right != nullptr) {
                        leftSubTreeMaxParentNode = leftSubTreeMaxNode;
                        leftSubTreeMaxNode = leftSubTreeMaxNode->right;
                    }

                    // b. 삭제 과정 진행 (노드 값 바꾸기 -> 연결관계 재정의 -> leftSubTreeMaxNode 완전 삭제)
                    // b-1. 삭제할 노드 값을 leftSubTreeMaxNode의 값으로 바꾸기
                    currNode->val = leftSubTreeMaxNode->val;
                    // b-2. 연결관계 재정의
                    // b-2-1. leftSubTreeMaxParentNode 가 currNode 인 경우 (삭제할 노드가 leftSubTreeMaxNode의 부모 노드인 경우)
                    if (leftSubTreeMaxParentNode == currNode) {
                        currNode->left = leftSubTreeMaxNode->left;
                    }
                    // b-2-2. 그 외의 경우
                    // leftSubTreeMaxNode의 왼쪽 노드 유무 상관 없이 연결(노드 없는 경우 nullptr 임)
                    else {
                        leftSubTreeMaxParentNode->right = leftSubTreeMaxNode->left;
                    }
                    // b-3. leftSubTreeMaxNode 완전 삭제
                    delete leftSubTreeMaxNode;
                    return root;
                    */

                    // a. 서브트리 탐색(해당 서브트리 안에서 최솟값 탐색)
                    // 오른쪽 서브트리 중 최솟값 노드
                    // 오른쪽 서브트리의 최상단 노드부터 시작
                    TreeNode* rightSubTreeMinNode = currNode->right;
                    // rightSubTreeMinNode의 부모 노드를 저장하기 위함
                    TreeNode* rightSubTreeMinParentNode = currNode;

                    // 서브트리 탐색 (탐색이 끝나면 반복문 종료)
                    // 종료할 때 자연스럽게 오른쪽 서브트리 중 최솟값 노드가 됨
                    while (rightSubTreeMinNode->left != nullptr) {
                        rightSubTreeMinParentNode = rightSubTreeMinNode;
                        rightSubTreeMinNode = rightSubTreeMinNode->left;
                    }

                    // b. 삭제 과정 진행 (노드 값 바꾸기 -> 연결관계 재정의 -> rightSubTreeMinNode 완전 삭제)
                    // b-1. 삭제할 노드 값을 rightSubTreeMinNode의 값으로 바꾸기
                    currNode->val = rightSubTreeMinNode->val;
                    // b-2. 연결관계 재정의
                    // b-2-1. rightSubTreeMinParentNode 가 currNode 인 경우 (삭제할 노드가 rightSubTreeMinNode의 부모 노드인 경우)
                    if (rightSubTreeMinParentNode == currNode) {
                        currNode->right = rightSubTreeMinNode->right;
                    }
                    // b-2-2. 그 외의 경우
                    // rightSubTreeMinNode의 오른쪽 노드 유무 상관 없이 연결(노드 없는 경우 nullptr 임)
                    else {
                        rightSubTreeMinParentNode->left = rightSubTreeMinNode->right;
                    }
                    // b-3. leftSubTreeMaxNode 완전 삭제
                    delete rightSubTreeMinNode;
                    return root;
                }
            }
            // 삭제 대상 노드의 값이 현재 노드의 값보다 작은 경우
            else if (key < currNode->val) {
                currParentNode = currNode;
                currNode = currNode->left;
            }
            // 삭제 대상 노드의 값이 현재 노드의 값보다 큰 경우
            else {
                currParentNode = currNode;
                currNode = currNode->right;
            }
        }
        // while 문을 탈출한 경우:
        //
        // BST 규칙에 따라 elem이 존재한다면
        // <1번 케이스>
        // 반드시 현재 노드의 왼쪽 서브트리에 있어야 하는데, 왼쪽 노드가 없으므로 존재할 수 없다.
        // <2번 케이스>
        // 반드시 현재 노드의 오른쪽 서브트리에 있어야 하는데, 오른쪽 노드가 없으므로 존재할 수 없다.
        //
        
        return init;
    }
};