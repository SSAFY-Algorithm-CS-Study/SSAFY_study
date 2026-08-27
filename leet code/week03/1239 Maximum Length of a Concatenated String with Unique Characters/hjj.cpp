#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int encoder(string s) {
    int code = 0;

    // a : 1
    // b : 10
    // c : 100
    for (char c : s) {
        code += (1 << (int(c) - int('a')));
    }
    return code;
}

int exponential(int a, int b) {
    int val = 1;
    while (b > 0) {
        val *= a;
        b--;
    }
    return val;
}

int maxLength(vector<string>& arr) {
    int n = arr.size();

    int combine_string_code;
    int new_string_code;
    int max_combine_string_code = 0;

    for (int subset_code = 0; subset_code < (1 << n); subset_code++) {
        combine_string_code = 0;
        for (int idx = 0; idx < n; idx++) {
            if (subset_code & (1 << idx)) {
                new_string_code = encoder(arr[idx]);
                if ((combine_string_code & new_string_code) == 0) {
                    combine_string_code += new_string_code;
                }
                else {
                    break;
                }
            }
        }
        if (max_combine_string_code < combine_string_code) max_combine_string_code = combine_string_code;
    }

    int max_digit = n;
    while (max_digit >= 0) {
        if (max_combine_string_code / exponential(2, max_digit)) return max_digit + 1;
        max_digit--;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);

    //vector<string> input_arr = { "un","iq","ue" };
    //vector<string> input_arr = { "cha","r","act","ers" };
    vector<string> input_arr = { "abcdefghijklmnopqrstuvwxyz" };

    printf("정답: %d", maxLength(input_arr));
    //printf("확인 : %d", exponential(6, 3));

    return 0;
}
