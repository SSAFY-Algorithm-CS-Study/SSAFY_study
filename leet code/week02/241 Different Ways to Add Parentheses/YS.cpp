/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 재귀                                    SS      WW   WW  */
/* Time Complexity   : O(3^n)                                  SSSSS   WW W WW  */
/* Space Complexity  : O(n)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
// 연산자를 만나면 왼쪽, 오른쪽을 구함
// left = 현재문자열.substr(0, 연산자)
// right = 현재문자열.str(연산자+1)
// left, right계산

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> answer;
        for(int i = 0;i<expression.length();i++){
            if(expression[i] =='*'||expression[i] =='-'||expression[i] =='+'){// 연산자가 나오면 연산자 기준 왼쪽, 오른쪽으로 나누기
                vector<int> left = diffWaysToCompute(expression.substr(0, i)); // 왼쪽에서 계산될 수 있는 경우의수
                vector<int> right = diffWaysToCompute(expression.substr(i+1)); //오른쪽에서 계산될 수 있는 경우의수 저장
                
                for(int j = 0;j<left.size();j++){
                    for(int k=0;k<right.size();k++){ // 연산자에 따라 계산해서 answer에 넣어줌 
                        if(expression[i] == '*') answer.push_back(left[j]*right[k]);
                        else if(expression[i] == '+') answer.push_back(left[j]+right[k]);
                        else answer.push_back(left[j]-right[k]);
                    }
                }
            }
        }
        if(answer.empty()) { // 연산자가 없으면 숫자만 남아있는거니까 숫자 그대로 넣어주기
            answer.push_back(stoi(expression));
        }
        return answer;
    }
};

