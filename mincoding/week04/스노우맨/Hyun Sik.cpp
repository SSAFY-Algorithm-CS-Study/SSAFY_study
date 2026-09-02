/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : 이분 탐색, BFS                          SS      WW   WW  */
/* Time Complexity   : O(N^2 * M * logN)                       SSSSS   WW W WW  */
/* Space Complexity  : O(N * M)                                   SS   WWW WWW  */
/* Note              : mincoding - 스노우맨                    SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>>& v, int mid, int startY, int startX, int targetY, int targetX)
{ // 눈사람이 세로로 최대 mid칸 이동할 수 있을 때
  // 시작 위치에서 보석 위치까지 도달할 수 있는지 BFS로 확인
    int N = v.size(); // 맵의 세로 크기
    int M = v[0].size(); // 맵의 가로 크기

    queue<pair<int, int>> q; // BFS에서 방문할 좌표를 저장할 큐
    vector<vector<bool>> visited(N, vector<bool>(M, false)); // 각 위치의 방문 여부를 저장할 벡터

    q.push({ startY, startX }); // 눈사람의 시작 위치를 큐에 삽입
    visited[startY][startX] = true; // 시작 위치 방문 처리

    while (!q.empty()) // 더 이상 방문할 위치가 없을 때까지 BFS 수행
    {
        int y = q.front().first; // 현재 위치의 y좌표
        int x = q.front().second; // 현재 위치의 x좌표
        q.pop(); // 현재 위치를 큐에서 제거

        if (y == targetY && x == targetX) // 현재 위치가 보석이 있는 위치라면 
        {
            return true; // 도달에 성공
        }

        int newX = x - 1; // 현재 위치의 왼쪽 칸 확인
        if (newX >= 0 && v[y][newX] != 0 && !visited[y][newX])
        { // 왼쪽 칸이 맵 내부이고, 이동 가능한 칸이며, 방문하지 않은 경우
            visited[y][newX] = true; // 왼쪽 칸 방문 처리
            q.push({ y, newX }); // BFS 탐색을 위해 큐에 삽입
        }

        newX = x + 1; // 현재 위치의 오른쪽 칸 확인
        if (newX < M && v[y][newX] != 0 && !visited[y][newX])
        { // 오른쪽 칸이 맵 내부이고, 이동 가능한 칸이며, 방문하지 않은 경우
            visited[y][newX] = true; // 오른쪽 칸 방문 처리
            q.push({ y, newX }); // BFS 탐색을 위해 큐에 삽입
        }

        for (int newY = y - 1; newY >= 0; newY--)
        { // 현재 위치에서 위쪽 방향으로 이동 가능한 위치 탐색
            int distance = y - newY; // 현재 위치에서 위쪽 칸까지의 세로 거리 계산
            if (distance > mid) // 이동 거리가 mid보다 크면  
            {
                break; // 더 위쪽으로 이동할 수 없으므로 탐색 종료
            }

            if (v[newY][x] != 0 && !visited[newY][x])
            { // 해당 위치가 이동 가능한 칸이고 아직 방문하지 않았다면
                visited[newY][x] = true; // 해당 위치 방문 처리
                q.push({ newY, x }); // BFS 탐색을 위해 큐에 삽입
            }
        }

        for (int newY = y + 1; newY < N; newY++)
        { // 현재 위치에서 아래쪽 방향으로 이동 가능한 위치 탐색
            int distance = newY - y; // 현재 위치에서 아래쪽 칸까지의 세로 거리 계산
            if (distance > mid) // 이동 거리가 mid보다 크면
            { 
                break; // 더 아래쪽으로 이동할 수 없으므로 탐색 종료
            }

            if (v[newY][x] != 0 && !visited[newY][x])
            { // 해당 위치가 이동 가능한 칸이고 아직 방문하지 않았다면
                visited[newY][x] = true; // 해당 위치 방문 처리
                q.push({ newY, x }); // BFS 탐색을 위해 큐에 삽입
            }
        }
    }

    return false; // BFS가 끝날 때까지 보석 위치에 도달하지 못했다면 실패
}

int main() {
    int N, M; // N : 맵의 세로 크기
              // M : 맵의 가로 크기
    cin >> N >> M; // 맵의 크기 입력
    vector<vector<int>> v(N, vector<int>(M)); // N 과 M을 크기로 하는 맵
    int snowmanY = -1; // 눈사람의 y좌표
    int snowmanX = -1; // 눈사람의 x좌표
    int jewelleryY = -1; // 보석의 y좌표
    int jewelleryX = -1; // 보석의 x좌표
    for (int i = 0; i < N; i++) // 맵의 모든 칸 입력
    {
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j]; // 현재 위치의 값 입력
            if (v[i][j] == 2) // 현재 위치가 눈사람이라면
            {
                snowmanY = i; // 눈사람의 y좌표 저장
                snowmanX = j; // 눈사람의 x좌표 저장
            }
            else if (v[i][j] == 3) // 현재 위치가 보석이라면
            {
                jewelleryY = i; // 보석의 y좌표 저장
                jewelleryX = j; // 보석의 x좌표 저장
            }
        }
    }

    int left = 0; // 이분 탐색의 최소 이동 거리
    int right = N - 1; // 세로 방향으로 이동할 수 있는 최대 거리
    int answer = N - 1; // 정답을 가능한 최대 이동 거리로
    while (left <= right) // 이동 가능한 최소 세로 거리를 이분 탐색
    {
        int mid = (left + right) / 2; // 현재 확인할 세로 이동 거리

        if (bfs(v, mid, snowmanY, snowmanX, jewelleryY, jewelleryX))
        { // 세로로 최대 mid칸 이동할 수 있을 때 보석까지 도달할 수 있다면
            answer = mid; // 현재 mid를 정답 후보로 저장
                          // 더 작은 이동 거리로도 도달 가능한지 확인하기 위해
            right = mid - 1; // 탐색 범위를 왼쪽 절반으로 줄임
        }
        else // 현재 mid 거리로는 보석까지 도달할 수 없으므로
        {
            left = mid + 1; // 더 큰 이동 거리를 확인
        }
    }

    cout << answer; // 보석까지 도달하기 위해 필요한 최소 세로 이동 거리 정답 출력
}