#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// 입력받은 연산자 문자에 맞는 연산을 두 숫자에 수행
int simple_compute(int num1, int num2, char oper) {
    if (oper == '+') {
        return num1 + num2;
    }
    else if (oper == '-') {
        return num1 - num2;
    }
    else if (oper == '*') {
        return num1 * num2;
    }
    else {
        return 0;
    }
}

// 분할 정복 알고리즘
// 연산자를 기준으로 왼쪽 부분식과 오른쪽 부분식으로 나누고,
// 각 부분식에서 나올 수 있는 모든 결과를 재귀적으로 구한 뒤,
// 현재 연산자로 모든 조합을 계산한다.
// 
// 연산자를 고르는 의미: 가장 마지막에 해당 연산을 진행하겠다
// 
//    ┌   2 * 3 - 4   ┐
// ┌  *  ┐        ┌ - ┐
// 2    3 - 4    2 * 3    4
//         . . . .
// 각 연산자를 기준으로 식을 왼쪽 부분식과 오른쪽 부분식으로 분할하고,
// 각 부분식에서 나올 수 있는 모든 계산 결과를 재귀적으로 구한다.
//
// 하나의 부분식도 괄호 배치 방법에 따라 여러 결과를 가질 수 있으므로,
// 함수의 반환형은 하나의 int가 아니라 vector<int>가 된다.
// 
vector<int> diffWaysToCompute(string expression) {
    // 리턴할 벡터
    vector<int> answer;
    // expression의 길이
    int n = static_cast<int>(expression.length());

    // 현재 보고 있는 문자
    char curr;

    // 현재 expression의 모든 문자를 살펴본다
    for (int idx = 0; idx < n; idx++) {
        curr = expression[idx];

        // 만약 현재 문자가 연산자라면
        if (curr == '+' || curr == '-' || curr == '*') {
            // <분할 및 정복>
            // 해당 문자의 인덱스를 기준으로 왼쪽 식과 오른쪽 식으로 나누고,
            // 두 식에 대해 diffWaysToCompute를 재귀 호출한 리턴값을 저장한다
            vector<int> left_expr = diffWaysToCompute(expression.substr(0, idx));
            vector<int> right_expr = diffWaysToCompute(expression.substr(idx + 1));

            // <결합>
            // 이 반복이 의미하는 것은
            // 왼쪽 식의 모든 결과들과 오른쪽 식의 모든 결과들을
            // 현재 연산자에 맞는 연산을 진행하겠다는 것이다.
            // 그 후, 연산 결과들을 모두 리턴하겠다는 뜻
            for (int left_expr_res : left_expr) {
                for (int right_expr_res : right_expr) {
                    answer.push_back(simple_compute(left_expr_res, right_expr_res, curr));
                }
            }
        }
    }

    // <기저 조건>
    // 연산자가 하나도 없다면 위의 반복문에서 answer에 값이 추가되지 않는다.
    // 따라서 answer가 비어 있다는 것은 현재 expression이 숫자 하나라는 뜻이다.
    if (answer.empty()) {
        answer.push_back(stoi(expression));
    }

    return answer;
}

// 결과 확인용
int main() {
    string expression = "2*3-4*5";
    printf("[");
    for (int elem : diffWaysToCompute(expression)) {
        printf("%d ", elem);
    }
    printf("]");
}