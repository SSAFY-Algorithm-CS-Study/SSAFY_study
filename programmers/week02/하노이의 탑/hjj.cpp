#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int num_of_disk, int start_column, int end_column, int via_column) {
    // 모든 디스크들을 start_column 에서 end_column 으로 옮기려면
    // 1. 우선 n번째 disk를 end_column 으로 옮기기 위해서,
    // 나머지 disk들을 start_column 에서 via_column 으로 옮긴다 (end_column을 경유해서)
    // 2. 그 후 n번째 disk를 start_column 에서 end_column 으로 옮기고
    // 3. 나머지 disk들을 via_column 에서 end_column 으로 옮긴다 (start_column을 경유해서)
    // 점화식과 같이 표현이 가능하므로 -> 재귀로 풀이

    // disk를 하나만 옮기는 경우
    // 그냥 start_column에서 end_column으로 바로 옮긴다
    // 재귀 호출이므로, 탈출하려면 return
    if (num_of_disk == 1) {
        answer.push_back({ start_column, end_column });
        return;
    }

    hanoi(num_of_disk - 1, start_column, via_column, end_column);
    answer.push_back({ start_column, end_column });
    hanoi(num_of_disk - 1, via_column, end_column, start_column);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3, 2);
    return answer;
}