/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 스택                                    SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : leet - 20 Valid Parentheses             SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stackS; // 문자를 쌓는 스택 생성

        for (int i = 0; i < s.length(); i++) // 받은 문자열 길이만큼 반복문 실행
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') // 여는 괄호라면 스택에 넣기
            {
                stackS.push(s[i]);
            }
            else // 닫는 괄호라면
            {
                if (stackS.empty()) // 스택이 비어있다면
                {
                    return false; // false 리턴(닫는 괄호가 나오는데 비여있으면 여는 괄호가 없는것이므로)
                }
                else if ((stackS.top() == '(' && s[i] == ')') || (stackS.top() == '{' && s[i] == '}') ||
                         (stackS.top() == '[' && s[i] == ']')) // 스택의 top과 현재 문자가 서로 대응되는 괄호라면 pop
                {
                    stackS.pop();
                }
                else // 아니라면 false 리턴
                {
                    return false;
                }
            }
        }
        if (!stackS.empty()) // 비어있지 않으면
        {
            return false; // false 리턴(여는 괄호가 남아있다는 것이므로)
        }
        return true; // 전부 아니라면 true 리턴(모든 괄호가 대응되는 경우)
    }
};