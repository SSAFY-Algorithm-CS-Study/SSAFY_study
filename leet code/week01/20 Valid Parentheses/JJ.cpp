/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 스택                                    SS      WW   WW  */
/* Time Complexity   : O(n)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(n)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //여는 괄호면 스택에 넣고 닫는 괄호면 마주보는 괄호 종류 확인. 대응되는 괄호가 아니면 false 리턴
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push('(');
            }
            else if(s[i] == ')'){
                if(st.empty() || st.top() != '(')
                    return false;
                else
                    st.pop();
            }
            else if(s[i] == '{'){
                st.push('{');
            }
            else if(s[i] == '}'){
                if(st.empty() || st.top() != '{')
                    return false;
                else
                    st.pop();
            }
            else if(s[i] == '['){
                st.push('[');
            }
            else if(s[i] == ']'){
                if(st.empty() || st.top() != '[')
                    return false;
                else
                    st.pop();
            }

        }
        
        if(!st.empty())
            return false;
            
        return true;
    }
};

int main(void)
{
  string s1 = "()", 
        s2 = "()[]{}",
        s3 = "(]", 
        s4 = "([])", 
        s5 = "([)]";
  Solution sol;
  cout << sol.isValid(s1) << sol.isValid(s2) << sol.isValid(s3) << sol.isValid(s4) << sol.isValid(s5);
}