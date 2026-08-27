#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// [주요 아이디어]
// 
// 가능한 모든 부분집합을 만든다
// 부분집합의 각 원소들을 이어가면서, 중복되는 문자가 있는 경우 해당 부분집합은 버린다
// 최대 문자열의 길이는 각 부분집합 별로 루프가 끝날 때마다 갱신
// 

// 문자열을 2진수로 해석하여 해당 2진수에 해당하는 정수로 리턴하는 함수
int encoder(string s) {
    // 리턴할 코드 값
    int code = 0;

    // 입력 문자열 s의 각 문자 별 코드 값
    // a : 1
    // b : 10
    // c : 100
    int code_of_character;

    for (char c : s) {
        // 영어 알파벳 순서대로, n번째라면 2의 (n -1)제곱 이다.
        code_of_character = 1 << (int(c) - int('a'));
        // 만약 더하기 연산과 비트 연산(or)을 진행했는데 서로 값이 같다면
        if ((code + code_of_character) == (code | code_of_character)) {
            // 정상적으로 인코딩
            code += code_of_character;
        }
        // 더하기 연산과 비트 연산의 결과값이 다르다면
        // 중복되는 문자가 있다는 뜻
        // ex) 1000 + 1010 = 10010, 1000 | 1010 = 1010 <- 서로 값이 다름
        else {
            // 0을 리턴한다
            return 0;
        }
    }
    return code;
}

// 2진수에 해당하는 정수로 표현된, code의 각 문자 개수를 리턴하는 함수
int num_of_characters(int code) {
    int n = 0;
    while (code > 0) {
        if (code % 2 == 1) n++;
        code = code >> 1;
    }
    return n;
}

int maxLength(vector<string>& arr) {
    // arr의 원소 개수
    int n = arr.size();

    // 조합 문자열 코드
    int combine_string_code;
    // 기존 조합 문자열에 새로 추가할 문자열의 코드
    int new_string_code;
    // 가능한 조합 문자열 길이의 최댓값
    int max_combine_string_code = 0;

    // subset_code 는 부분집합의 원소가 어떤 것들이 들어있는지를 나타내는 코드이다.
    // 예를 들어 arr가 아래와 같을 때
    // elem "a" "b" "c" "d" "e"
    // idx   0   1   2   3   4
    // subset_code 가 1이면, idx가 0인 원소 "a"를 포함하는 부분집합이다.
    // subset_code 가 10011 이면, idx가 0, 3, 4인 원소 "a", "d", "e" 를 포함하는 부분집합이다.
    for (int subset_code = 0; subset_code < (1 << n); subset_code++) {
        // 조합 문자열 코드는 매 루프마다(=매 조합마다) 초기화한다
        combine_string_code = 0;

        // subset_code에서 가리키는 arr의 index를 찾기 위한 루프
        // 즉 현재 부분집합의 모든 원소들을 순회하는 과정이다
        for (int idx = 0; idx < n; idx++) {
            // 만약 subset_code에서 가리키는 arr의 index 라면
            if (subset_code & (1 << idx)) {
                // arr[idx] 에 대한 새로운 조합 문자열 코드를 생성한다
                new_string_code = encoder(arr[idx]);

                // 만약 조합 문자열 코드가 0이라면(즉, arr[idx] 내에 중복된 문자가 존재한다면)
                // 현재 부분집합은 스킵한다 (문제 조건을 위배한 부분집합 이므로)
                if (!new_string_code) break;

                // 만약 새로운 문자열에 중복된 문자가 존재하지 않을 경우 (비트 연산을 통해 확인)
                // 조합한다 (combine_string_code += new_string_code)
                // 
                // ex 1) combine_string_code: 10010, new_string_code: 101
                // combine_string_code & new_string_code == 0 이므로 combine_string_code에 new_string_code를 더함
                // 
                // ex 2) combine_string_code: 10010, new_string_code: 10
                // combine_string_code & new_string_code == 2(이진수 기준 2의 1제곱 자리가 서로 1이므로, 2가 된다)이므로
                // 현재 부분집합은 문제 조건을 위배한 부분집합이므로
                // 부분집합 내 모든 요소 확인할 필요 없이 break
                if ((combine_string_code & new_string_code) == 0) combine_string_code += new_string_code;
                else break;
            }
        }
        // 가능한 조합 문자열 길이의 최댓값을 갱신함
        if (num_of_characters(max_combine_string_code) < num_of_characters(combine_string_code)) {
            max_combine_string_code = combine_string_code;
        }
    }

    // 가능한 조합 문자열 길이의 최댓값을 리턴
    return num_of_characters(max_combine_string_code);
}

int main() {
    ios_base::sync_with_stdio(false);

    // 확인용 테케
    //vector<string> input_arr = { "un","iq","ue" };
    //vector<string> input_arr = { "cha","r","act","ers" };
    vector<string> input_arr = { "abcdefghijklmnopqrstuvwxyz" };

    printf("정답: %d", maxLength(input_arr));

    return 0;
}
