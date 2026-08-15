/********************************************************************************/
/* File Name         : Hyun sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 재귀                                    SS      WW   WW  */
/* Time Complexity   : O(2^n)                                  SSSSS   WW W WW  */
/* Space Complexity  : O(n)                                       SS   WWW WWW  */
/* Note              : programmers : 하노이의 탑               SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <string>
#include <vector>
using namespace std;

void hanoi(int n, int start, int mid, int end, vector<vector<int>>& answer)
{
    if (n == 1) // 이동할 원판이 1개일 때는 시작 기둥에서 목적지 기둥으로 바로 이동
    {
        answer.push_back({ start, end });
        return;
    }

    hanoi(n - 1, start, end, mid, answer); // 맨 아래 원판을 제외한 (n-1)개의 원판을 start -> mid 기둥으로 이동

    answer.push_back({ start, end }); // 가장 큰 원판(n번째)을 start -> end 기둥으로 이동

    hanoi(n - 1, mid, start, end, answer); // mid 기둥에 있던 (n-1)개의 원판을 mid -> end 기둥으로 이동
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer; // 정답 벡터

    hanoi(n, 1, 2, 3, answer); // 정답 벡터에 n개의 원판 움직이는 각 결과들 기록
    return answer; // 정답 벡터 리턴
}