/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : BST, 재귀                               SS      WW   WW  */
/* Time Complexity   : O(h)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(h)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};*/
 
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root) //널이면 널 리턴
            return root;


        if(root->val == key){
            //둘 다 NULL이면 단순 삭제
            if(root->left == NULL && root->right == NULL)
                return NULL;

            //한쪽만 NULL일 때 NULL 아닌 부분을 root로 변경
            else if(root->left == NULL && root->right){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            else if(root->left && root->right == NULL){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            //양쪽다 값이 있을 때, 오른쪽 서브트리의 min값을 찾아 대체
            else{
                TreeNode *temp = root->right; //오른쪽 서브트리 포인팅
                
                while(temp->left) //오른쪽 서브트리의 맨왼쪽 리프노드 찾기(최소값)
                    temp = temp->left;

                root->val = temp->val; //리프노드의 값을 부모 노드로 옮기기
                root->right = deleteNode(root->right, temp->val); //리프노드 삭제
            }
        }

        //재귀를 통해 key값을 가진 노드 찾기. 찾으면 연산 진행 후 바뀐 상태를 리턴
        else if(root->val < key) 
            root->right = deleteNode(root->right, key);
        
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        
        return root;
    }
};

/*
void printNode(TreeNode* node)
{
    if(node == nullptr)
        cout << "null";
    else
        cout << node->val;
}

int main(void)
{
    Solution sol;

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    TreeNode *answer = sol.deleteNode(root, 3);

    TreeNode *root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(6);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    TreeNode *answer2 = sol.deleteNode(root2, 0);


    printNode(answer);
    cout << ' ';

    printNode(answer->left);
    cout << ' ';

    printNode(answer->right);
    cout << ' ';

    printNode(answer->left->left);
    cout << ' ';

    printNode(answer->left->right);
    cout << ' ';

    printNode(answer->right->left);
    cout << ' ';

    printNode(answer->right->right);
    cout << '\n';


    printNode(answer2);
    cout << ' ';

    printNode(answer2->left);
    cout << ' ';

    printNode(answer2->right);
    cout << ' ';

    printNode(answer2->left->left);
    cout << ' ';

    printNode(answer2->left->right);
    cout << ' ';

    printNode(answer2->right->left);
    cout << ' ';

    printNode(answer2->right->right);
    cout << '\n';
}*/