#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    // 입력 배열 크기
    int n = prices.size();
    // prices_stack의 각 원소값 저장용 변수
    int price;

    // prices를 stack으로 변경
    // [1, 2, 3, 2, 3] -> [3, 2, 3, 2, 1]
    vector<int> prices_stack;
    while (!prices.empty()) {
        prices_stack.push_back(prices.back());
        prices.pop_back();
    }

    // saving 이라는 stack 정의
    // ((saving의 크기) - 1)을 answer에 저장
    vector<int> saving;

    // 입력 배열 크기만큼 반복
    for (int i = 0; i < n; i++) {
        // 현재 인덱스의 값 저장(스택이므로, .back()으로 값 저장 가능)
        // price는 prices의 i 인덱스 순
        price = prices_stack.back();

        // 1. saving에 숫자들을 넣어감
        // 먼저 saving에 prices_stack의 맨 위(.back()) 숫자를 저장하고
        // prices_stack 에서 제거
        // 만약 빼는 숫자가 price 보다 작은 경우, 가격이 떨어지게 된 시점이므로 반복문에서 탈출
        while (!prices_stack.empty()) {
            saving.push_back(prices_stack.back());
            prices_stack.pop_back();
            if (saving.back() < price) {
                break;
            }
        }

        // 2. answer에 값 저장
        // saving 에는 현재 인덱스의 값(price)이 포함되어 있으모로, 전체 개수에서 1을 빼야 함
        answer.push_back(saving.size() - 1);

        // 3. prices_stack 원상복구
        // 단, 복구 시에 price는 제외하고 복구할 것이므로
        // 반복문 진행 후, 맨 위(.back() = price) 제거
        while (!saving.empty()) {
            prices_stack.push_back(saving.back());
            saving.pop_back();
        }
        prices_stack.pop_back();
    }

    return answer;
}