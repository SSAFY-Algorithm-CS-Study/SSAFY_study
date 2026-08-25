#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> maps)
{
    // 가로(n), 세로(m) 크기
    int m = static_cast<int>(maps.size());
    int n = (m > 0) ? static_cast<int>(maps[0].size()) : 0;

    // dx, dy 별로 idx 0, 1, 2, 3일 때
    // right, left, up, down
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    // bfs { { x, y }, d }
    queue<pair<pair<int, int>, int >> routes;
    routes.push({ { 0, 0 }, 0 });
    // 지나온 길 [x][y]
    // 기존에 방문한 곳의 좌표를 저장하는 것에서, 각 좌표를 인덱스로 하는 값에 +1 하는 것으로 수정
    vector<vector<int>> visited(n, vector<int>(m, 0));
    visited[0][0]++;

    // 현재 좌표
    pair<int, int> curr_pos;

    // 현 좌표 기준 이동한 거리
    int d = 0;

    // 이동할 좌표
    int x, y;

    while (!routes.empty()) {
        curr_pos = routes.front().first;
        d = routes.front().second;
        routes.pop();
        // 이동거리 +1
        d++;
        // 목적지에 도달한 경우 이동거리를 리턴하고 종료
        if (curr_pos.first == n - 1 && curr_pos.second == m - 1) {
            return d;
        }

        for (int movement_idx = 0; movement_idx < 4; movement_idx++) {
            x = curr_pos.first + dx[movement_idx];
            y = curr_pos.second + dy[movement_idx];
            // 맵을 벗어나는 경우
            if (x < 0 || x > n - 1 || y < 0 || y > m - 1) {
                continue;
            }
            // 이미 방문한 길인 경우
            else if (visited[x][y]) {
                continue;
            }
            // 방문하지 않은 길이면서, 갈 수 있는 길인 경우
            else if (maps[y][x]) {
                // visited에 추가
                visited[x][y]++;
                // routes에 추가
                routes.push({ { x, y }, d });
            }
        }
    }

    // 목적지에 도달하지 못한 경우 -1 리턴
    return -1;
}
