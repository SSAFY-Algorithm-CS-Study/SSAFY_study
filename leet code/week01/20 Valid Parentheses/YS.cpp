/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : Park Yeonseo                            SSSSS   WW   WW  */
/* Algorithm         : stack                                   SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){ // 여는 괄호이면 스택에 넣기
                v.push_back(s[i]);
            }
            else{
                if(v.empty()){ // 닫히는 괄호인데 스택은 비어있으면 false
                    return false;
                }
                if((s[i] == ')'&& v.back() == '(')||(s[i] == ']'&& v.back() == '[')||(s[i] == '}'&& v.back() == '{')){
                    v.pop_back(); // 닫히는 괄호이고 스택에 맞는 여는 괄호가 있으면 pop
                }
                else{
                    return false; // 맞는 괄호가 없으면 false 반환
                }
            }
        }
        return v.empty(); // 스택이 비어있으면 true 반환
    }
};
