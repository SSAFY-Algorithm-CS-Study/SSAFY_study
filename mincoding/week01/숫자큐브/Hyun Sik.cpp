/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 구현, 시뮬레이션                        SS      WW   WW  */
/* Time Complexity   : O(N^2 + K * S^2)                        SSSSS   WW W WW  */
/* Space Complexity  : O(N^2)                                     SS   WWW WWW  */
/* Note              : 민코딩 - 숫자 큐브                      SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 입출력 속도 향상 (시간 초과 방지)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num; // 행렬의 크기 입력받기

    vector<vector<int>> v(num, vector<int>(num)); // 행, 열 길이가 같도록 2차원 벡터 생성
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cin >> v[i][j]; // 행렬 값 입력받기
        }
    }

    int count;
    cin >> count; // 회전 횟수 입력받기
    for (int i = 0; i < count; i++)
    {
        int y, x, size, radian;

        cin >> y >> x >> size >> radian; // 회전 시작 좌표, 회전할 정사각형의 한 변의 길이, 회전 각도 입력받기

        radian %= 4; // 360도 회전은 원래 상태이므로 4로 나눈 나머지 값만 사용

        vector<vector<int>> v2 = v; // 회전 후 값을 저장할 벡터 생성, 회전 전 값으로 초기화

        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                int originY = y + j; // 회전 전 좌표의 y값
                int originX = x + k; // 회전 전 좌표의 x값

                if (radian == 1) // 90도 회전
                {
                    v2[y + (size - 1 - k)][x + j] = v[originY][originX];
                }
                else if (radian == 2) // 180도 회전
                {
                    v2[y + (size - 1 - j)][x + (size - 1 - k)] = v[originY][originX];
                }
                else if (radian == 3) // 270도 회전
                {
                    v2[y + k][x + (size - 1 - j)] = v[originY][originX];
                }
            }
        }

        v = v2; // 회전 후 값을 저장한 벡터를 원래 벡터에 대입
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            cout << v[i][j] << (j == num - 1 ? "" : " "); // 마지막 열이 아니라면 공백 출력
        }
        cout << "\n";
    }

    return 0;
}