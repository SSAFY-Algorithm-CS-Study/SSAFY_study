#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> return_subsets;
    nums.size();
    int num_of_subsets = 0;
    // 이진수로 시작 (0000)
    // 1씩 더하면서, 각 자릿수에 맞는 원소들로 벡터에 넣기
    // 벡터를 return_subsets 에 추가

    return return_subsets;
}

int main() {
    vector<int> input_set = { 1, 2, 3 };
    cout << "[";
    for (vector<int> subset : subsets(input_set)) {
        cout << "[";
        for (int elem : subset) {
            cout << elem << " ";
        }
        cout << "]";
    }
    cout << "]";
}