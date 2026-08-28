#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>

using namespace std;

string expression = "2*3-4*5";

// [주요 아이디어]
// 숫자와 연산 기호를 따로 저장한 다음
// 재귀 호출로 모든 경우의 수 탐색
// 
// 숫자를 따로 저장하는 vector 인 nums와
// 연산 기호를 따로 저장하는 vector 인 operators를
// 재귀 호출의 parameter로 사용하면서 연산 진행
// 
// 예시: 1 + 2 * 3 - 4 인 경우
// nums: [1, 2, 3, 4]
// operators: [+, *, -]
// 
// 1. nums의 길이는 항상 operators 보다 1이 큰 점을 이용한다
// 2. 경우의 수 탐색
// a) new_nums: [(1 + 2), 3, 4], new_opers: [*, -]
// b) new_nums: [1, (2 * 3), 4], new_opers: [+, -]
// c) new_nums: [1, 2, (3 - 4)], new_opers: [+, *]
// new_nums와 new_opers를 입력으로 하여 재귀 호출하며 반복
// 
// 결과:
// 쓰레기값도 같이 포함되어 있었는데, 원인을 추적하기 위해 디버깅을 진행해봤으나
// 디버깅으로 파악하기가 굉장히 어려웠기 때문에 해당 방법 포기
// 

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

int compute(vector<int>& nums, vector<char>& opers, vector<int>& results) {
    int opers_size = static_cast<int>(opers.size());
    if (opers_size == 0) return nums[0];

    vector<int> new_nums(opers_size);
    vector<char> new_opers(opers_size - 1);
    int new_num;

    for (int i = 0; i < opers_size; i++) {
        new_num = simple_compute(nums[i], nums[i + 1], opers[i]);
        new_nums[i] = new_num;
        if (i == 0) {
            for (int j = 1; j <= opers_size - 1; j++) {
                new_nums[j] = nums[j + 1];
                new_opers[j - 1] = opers[j];
            }
        }
        else if (i == (opers_size - 1)) {
            for (int j = 0; j < opers_size - 1; j++) {
                new_nums[j] = nums[j];
                new_opers[j] = opers[j];
            }
        }
        else {
            for (int j = 0; j < i; j++) {
                new_nums[j] = nums[j];
                new_opers[j] = opers[j];
            }
            for (int j = i + 1; j <= opers_size - 1; j++) {
                new_nums[j] = nums[j + 1];
                new_opers[j - 1] = opers[j];
            }
        }
        results.push_back(compute(new_nums, new_opers, results));
    }
}

vector<int> diffWaysToCmpute(string expression) {
    int n = static_cast<int>(expression.length());

    vector<int> nums;
    vector<char> operators;
    vector<int> answer;

    char curr;
    int first_digit;
    int second_digit;

    for (int idx = 0; idx < n; idx++) {
        curr = expression[idx];

        if (curr == '+' || curr == '-' || curr == '*') {
            operators.push_back(curr);
            continue;
        }
        else {
            first_digit = int(curr) - int('0');
            if (idx + 1 != n) {
                char next = expression[idx + 1];
                second_digit = int(next) - int('0');
                if (second_digit >= 0 && second_digit <= 9) {
                    nums.push_back(10 * first_digit + second_digit);
                    idx++;
                    continue;
                }
            }
            nums.push_back(first_digit);
            continue;
        }
    }

    printf("현재 nums: ");
    for (int elem : nums) printf("%d ", elem);
    printf("\n");
    printf("현재 operators: ");
    for (char elem : operators) printf("%c ", elem);
    printf("\n");

    compute(nums, operators, answer);

    return answer;
}

int main() {
    printf("[");
    for (int elem : diffWaysToCmpute(expression)) {
        printf("%d ", elem);
    }
    printf("]");
}