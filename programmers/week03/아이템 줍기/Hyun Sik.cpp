/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : BFS                                     SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : 프로그래머스 - 아이템 줍기              SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0; // 정답 정수
    vector<vector<int>> v(102, vector<int>(102, 0));
    // 문제의 조건에 따라 직사각형의 모든 좌표값은 1 이상 50 이하인 자연수이므로
    // 원래는 51로 크기를 지정하면 되지만 만약 1, 1 과 2, 1 사이에 선이 없는데
    // 모서리라는 이유만으로 건너가게 되면 안되기 때문에 일부러 두배를 해서 빈 공간을 만들고
    // 아예 못 지나가도록 설정
    for (int i = 0; i < rectangle.size(); i++) // 입력받는 rectangle 벡터의 크기만큼 반복문 실행
    {
        int x1 = rectangle[i][0] * 2; // 첫번째 x좌표
        int y1 = rectangle[i][1] * 2; // 첫번째 y좌표
        int x2 = rectangle[i][2] * 2; // 두번째 x좌표
        int y2 = rectangle[i][3] * 2; // 두번째 y좌표

        for (int y = y1; y <= y2; y++) // 첫번째 y좌표부터 두번째 y좌표까지
        {
            for (int x = x1; x <= x2; x++) // 첫번째 x좌표부터 두번째 x좌표까지
            {
                if (x > x1 && x < x2 && y > y1 && y < y2) // 직사각형 내부 좌표는 
                {
                    v[y][x] = 2; // 2로 설정
                }
                else
                {
                    if (v[y][x] != 2) // 직사각형 내부가 아니면
                    {
                        v[y][x] = 1; // 테두리를 1로 설정
                    }
                }
            }
        }
    }

    // 캐릭터와 아이템 위치 모두 2배
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    queue<pair<int, int>> q; // BFS 좌표 담을 큐
    vector<vector<int>> distance(102, vector<int>(102, 0)); // 시작점부터 거리를 담을 벡터

    q.push({ characterY, characterX }); // 시작점 설정
    distance[characterY][characterX] = 1; // 방문 처리까지 생각하도록 1부터 시작
                                          // 0이면 방문 안한 것으로 생각하기 때문에

    // 상하좌우 이동을 위한 방향 배열                                      
    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };
    while (!q.empty()) // 큐가 비어있지 않을 때 까지 반복문 실행
    {
        int y = q.front().first;  // y좌표
        int x = q.front().second; // x 좌표
        q.pop(); // 큐 값 제거

        if (y == itemY && x == itemX) // 현재 위치가 아이템의 위치라면
        {
            answer = distance[y][x]; // 정답은 현재의 거리
            break; // 반복문 종료
        }

        for (int i = 0; i < 4; i++) // 상하좌우를 판단하기 위해 
        {
            // 새로운 좌표를 설정 
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (v[ny][nx] == 1 && distance[ny][nx] == 0) // 새로운 좌표가 테두리이고 
            {                                            // 아직 방문 안한 곳이라면
                distance[ny][nx] = distance[y][x] + 1; // 바로 전 거리에서 +1 한 거리를 새 거리로 설정
                q.push({ ny, nx }); // 큐에 현재 위치를 대입
            }
        }
    }

    return (answer - 1) / 2; // 처음에 거리를 1로 설정했기 때문에 -1을 하고 
                             // 전체를 2배해서 판단했기 때문에 /2 한 값을 정답 리턴
}