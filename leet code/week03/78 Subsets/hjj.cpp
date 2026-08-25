#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// subset_code 정의
// subset_code 는 2 ^ (nums.size()) 를 넘어설 수 없다
// 예시: nums의 원소 개수가 3개일 때, subset_code의 최대는 이진수 기준 111_(2) = 7_(10) 이다.
// 즉 1000_(2) = 8_(10)을 넘어설 수 없다.
// subset_code를 이진수로 표현했을 때, n번째 자릿수는 nums의 n-1 번째 원소의 유무를 가리킨다(0: 없음, 1: 있음)
// 예로, 100_(2)인 경우 nums의 2번째 원소가 있음을 나타냄
// 두번째 예로, 101_(2)인 경우 nums의 0번째, 2번째 원소가 있음을 나타냄

// 첫번째 풀이
// 가능한 모든 subset_code를 순회하면서 decode 한다
// 실제 subset 형태로 변환 후, answer에 넣는다.
// decode 하는 과정에서 curr_code를 쉬프트 연산하면서
// 각 자릿수를 모두 체크하는 식으로 간다.
// 실행시간 3ms
/*
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> answer;

    for (int subset_code = 0; subset_code < (1 << nums.size()); subset_code++) {
        vector<int> subset;
        int curr_code = subset_code;
        int nums_idx = 0;

        while (curr_code > 0) {
            if (curr_code & 1) subset.push_back(nums[nums_idx]);
            curr_code = curr_code >> 1;
            nums_idx++;
        }

        answer.push_back(subset);
    }
    return answer;
}
*/

// 두번째 풀이
// 가능한 모든 subset_code를 순회하면서 decode 한다
// 실제 subset 형태로 변환 후, answer에 넣는다.
// decode 하는 과정에서 subset_code 자체에 변화 없이 자릿수 체크를 진행한다
// 실행시간 0ms
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> answer;

    for (int subset_code = 0; subset_code < (1 << n); subset_code++) {
        vector<int> subset;

        for (int nums_idx = 0; nums_idx < n; nums_idx++) {
            if (subset_code & (1 << nums_idx)) subset.push_back(nums[nums_idx]);
        }

        answer.push_back(subset);
    }
    return answer;
}

// 확인용
int main() {
    vector<int> input_set = { 1, 2, 3, 4, 5 };

    cout << "[";
    for (vector<int> subset : subsets(input_set)) {
        cout << "[";
        for (int elem : subset) {
            cout << elem << ", ";
        }
        cout << "],";
    }
    cout << "]";

    return 0;
}