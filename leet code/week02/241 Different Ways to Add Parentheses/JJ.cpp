/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 재귀                                    SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //expression에 여러 방식으로 괄호를 치는 경우 나올 수 있는 모든 계산 결과를 담은 벡터를 반환한다(가능한 모든 경우의 수 탐색)
    vector<int> dfs(const string& str)
    {
        //기저 사례 - 숫자로만 구성된 문자열일 경우 나눌 필요 없으므로 바로 반환
        //연산자가 포함된 문자열은 최소 3자리 이상이므로
        if(str.length() <= 2)
            return {stoi(str)};
        
        vector<int> result;

        //연산자를 발견할 때마다 그 지점을 기준으로 식을 두 부분으로 나눈다
        for(int i = 0; i < str.length(); i++){
            char op = str[i];

            //연산자를 기준으로 왼/오 두 식으로 분리
            if(op == '+' || op == '-' || op == '*'){
                string left = str.substr(0, i);
                string right = str.substr(i+1);

                vector<int> leftCandidate = dfs(left); //왼쪽 부분식에서 만들 수 있는 모든 결과를 재귀적으로 구한다
                vector<int> rightCandidate = dfs(right); //오른쪽 부분식에서 만들 수 있는 모든 결과를 재귀적으로 구한다

                //왼쪽과 오른쪽 식에서 나올 수 있는 모든 결과를 하나씩 조합해 현재 연산자로 계산한다
                for(int i = 0; i < leftCandidate.size(); i++){
                    for(int j = 0; j < rightCandidate.size(); j++){
                        if(op == '+')
                            result.push_back(leftCandidate[i] + rightCandidate[j]);
                        else if(op == '-')
                            result.push_back(leftCandidate[i] - rightCandidate[j]);
                        else
                            result.push_back(leftCandidate[i] * rightCandidate[j]);
                    }
                }
            }
        }
        
        return result;
    }

    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);
    }
};

int main(void)
{
    Solution sol;
    vector<int> result1 = sol.diffWaysToCompute("2-1-1") , result2 = sol.diffWaysToCompute("2*3-4*5");

    for(int n : result1)
        cout << n << ' ';
    cout << '\n';
    for(int n : result2)
        cout << n << ' ';
}