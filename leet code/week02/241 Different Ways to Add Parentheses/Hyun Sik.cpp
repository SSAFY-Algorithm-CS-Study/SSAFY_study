/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 재귀                                    SS      WW   WW  */
/* Time Complexity   : O(2^N) ~ O(4^N / \sqrt{N})              SSSSS   WW W WW  */
/* Space Complexity  : O(2^N * N)                                 SS   WWW WWW  */
/* Note              : leet : 241 Different Ways to Add Par…   SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> answer; // 정답 벡터
        for (int i = 0; i < expression.length(); i++) // 문자열의 길이동안 반복문 실행
        {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') // 연재 문자열의 문자가 연산자일 경우
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, i)); // 연산자를 기준으로 왼쪽 문자열을 재귀적으로 호출하여 결과를 left 벡터에 저장
                vector<int> right = diffWaysToCompute(expression.substr(i+1)); // 연산자를 기준으로 오른쪽 문자열을 재귀적으로 호출하여 결과를 right 벡터에 저장

                for (int l : left) // left 벡터의 모든 원소에 대해 반복
                {
                    for (int r : right) // right 벡터의 모든 원소에 대해 반복
                    {
                        if (expression[i] == '+') // 현재 문자가 연산자 '+'일 경우
                        {
                            answer.push_back(l + r); // left 벡터의 원소와 right 벡터의 원소를 더한 값을 answer 벡터에 추가
                        }
                        else if (expression[i] == '-') // 현재 문자가 연산자 '-'일 경우
                        {
                            answer.push_back(l - r); // left 벡터의 원소와 right 벡터의 원소를 뺀 값을 answer 벡터에 추가
                        }
                        else if (expression[i] == '*') // 현재 문자가 연산자 '*'일 경우
                        {
                            answer.push_back(l * r); // left 벡터의 원소와 right 벡터의 원소를 곱한 값을 answer 벡터에 추가
                        }
                    }
                }
            }           
        }

        if (answer.empty()) // answer 벡터가 비어있을 경우 (즉, 연산자가 없는 경우)
        {
            answer.push_back(stoi(expression)); // 문자열을 정수로 변환하여 answer 벡터에 추가
        }

        return answer; // 정답 벡터 리턴
    }
};