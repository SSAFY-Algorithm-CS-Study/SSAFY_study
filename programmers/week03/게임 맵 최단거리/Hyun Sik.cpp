/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : BFS, 큐                                 SS      WW   WW  */
/* Time Complexity   : O(h * w) (h: 높이, w: 너비)             SSSSS   WW W WW  */
/* Space Complexity  : O(h * w) (h: 높이, w: 너비)                SS   WWW WWW  */
/* Note              : 프로그래머스 - 게임 맵 최단거리         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int height = maps.size(); // maps 벡터의 크기
    int width = maps[0].size(); // maps 벡터 안에 있는 벡터의 크기

    vector<vector<int>> distance(height, vector<int>(width, 0)); // 거리를 담을 벡터
    queue<pair<int, int>> q; // 좌표를 넣을 큐

    q.push({0, 0}); // 큐의 초기값을 0, 0 으로
    distance[0][0] = 1; // 기본 거리를 1로

    int dy[4] = {-1, 1, 0, 0}; // 상하좌우
    int dx[4] = {0, 0, -1, 1}; // 상하좌우

    while (!q.empty()) // 큐가 비어있지 않다면 반복문 실행
    {
        int y = q.front().first; // 큐의 처음 값의 처음값, 즉 첫 값의 y좌표
        int x = q.front().second; // 큐의 처음 값의 두번째 값, 즉 첫 값의 x좌표
        q.pop(); // 처음 들어온 값 제거

        if (y == height - 1 && x == width - 1) // 상대 진영 좌표에 왔다면
        {
            return distance[y][x]; // 거리 리턴
        }            

        for (int i = 0; i < 4; i++) // 상하좌우로 갈 수 있는 길인지 확인하기 위해 반복문 실행
        {
            int newY = y + dy[i]; // 새로운 y좌표
            int newX = x + dx[i]; // 새로운 x좌표

            if (newY < 0 || newY >= height || newX < 0 || newX >= width) // 좌표가 maps를 벗어난다면
            {
                continue; // 아래 실행 X
            }                

            if (maps[newY][newX] == 0) // 새로운 좌표의 값이 0이면
            {
                continue; // 아래 실행 X
            }                

            if (distance[newY][newX] != 0) // 새로운 좌표의 거리 벡터값이 0이 아니라면(이미 온 곳) 
            {
                continue; // 아래 실행 X
            }                

            distance[newY][newX] = distance[y][x] + 1; // 새로운 좌표의 거리 값을 이전 좌표의 거리에서 +1 한 값을 대입
            q.push({newY, newX}); // 큐에 새로운 좌표를 대입
        }
    }

    return -1; // 만족을 못한다면 결국 상대 진영 좌표에 도달하지 못한다는 것이므로 -1 리턴
}