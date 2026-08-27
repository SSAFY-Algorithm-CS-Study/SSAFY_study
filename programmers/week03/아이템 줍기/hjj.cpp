#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

// [메인 아이디어]
// 
// 해당 문제는 2가지 파트로 나뉜다
// 1. 이동 가능한 길을 구해내는 것
// 2. 해당 길을 따라 최소 거리를 구하는 것
// 
// 1. 이동 가능한 길을 구해내는 것
// 단순 구현이다. 단 아래 예시와 같은 상황을 보자
//   1  2  3  4  5 (x)
// 1 .  □ □ □ .
// 2 .  □ .  □ □
// 3 .  □ .  □ □
// 4 .  □ .  □ .
// 5 .  □ □ □ .
// (y)
// 
// (4, 2), (5, 2), (4, 3), (5, 3) 좌표 부분을 살펴보면
// 문제 조건에 따르면 (4, 2) -> (4, 3)으로 바로 갈 수가 없다
// 하지만 다른 조건을 주지 않는 한, BFS를 이용해 탐색할 경우 (4, 2) -> (4, 3)도 가능한 경로이다
// 따라서 이를 해결하기 위해, 전체 맵 사이즈를 2배로 늘리는 방식을 선택했다.
// 
// 2. 해당 길을 따라 최소 거리를 구하는 것
// BFS를 이용해 탐색한다.
// 단, 해당 문제의 경우 처음 시작하는 좌표가 항상 x나 y가 양수이므로
// 최대로 가능한 x와 y 조건만 유의해서 풀이하면 된다.
// 해당 풀이에서는 길을 저장하는 vector 및 visited의 크기를 102 X 102로 설정했다.
//   0      1 ~ 100    101
// (경계) (실제 이동) (경계)
// 

// 추가하려는 길 좌표가 이미 다른 사각형 영역 안에 있는지를 판단하는 함수
// 해당 함수를 이용하여 이동 가능한 길인지를 판별
bool isInside(vector<pair<pair<int, int>, pair<int, int>>> bounds, int x, int y) {
    int left_bound_x;
    int left_bound_y;
    int right_bound_x;
    int right_bound_y;

    for (pair<pair<int, int>, pair<int, int>> bound : bounds) {
        left_bound_x = bound.first.first;
        left_bound_y = bound.first.second;
        right_bound_x = bound.second.first;
        right_bound_y = bound.second.second;

        // 사각형 영역 안에 있다면 true를 리턴하고 바로 종료
        if ((x > left_bound_x) && (x < right_bound_x) && (y > left_bound_y) && (y < right_bound_y)) {
            return true;
        }
    }

    // 모든 영역을 살펴봐도 영역 안에 있지 않다면 false 리턴
    return false;
}


int solution(vector<vector<int>> rectangles, int characterX, int characterY, int itemX, int itemY) {
    // 좌표평면을 2배로 늘림
    // 길인지 아닌지 여부만 표시할 것이므로 bool로 저장한다
    vector<vector<bool>> plane(102, vector<bool>(102, 0));

    // 각 사각형 영역의 x, y 값을 저장하기 위함
    vector<pair<pair<int, int>, pair<int, int>>> bounds;

    // 사각형의 각 꼭짓점의 x, y를 저장할 변수
    // left_cortex_x, left_cortex_y: 왼쪽 아래 좌표의 x, y
    // right_cortex_x, right_cortex_y: 오른쪽 위 좌표의 x, y
    int left_cortex_x;
    int left_cortex_y;
    int right_cortex_x;
    int right_cortex_y;

    for (vector<int> rectangle_info : rectangles) {
        // 각 좌표에도 2배
        left_cortex_x = rectangle_info[0] * 2;
        left_cortex_y = rectangle_info[1] * 2;
        right_cortex_x = rectangle_info[2] * 2;
        right_cortex_y = rectangle_info[3] * 2;

        // 이동 가능한 길 표시
        // (좌표) | 1 : 비트 연산을 통해, 중복해서 기록하는 경우에도 1(true)을 유지할 수 있도록 한다
        for (int x = left_cortex_x; x <= right_cortex_x; x++) {
            // x가 사각형의 왼쪽, 오른쪽 변의 x좌표와 같은 경우
            if (x == left_cortex_x || x == right_cortex_x) {
                // 왼쪽, 오른쪽 변에 위치한 좌표들에 대해 길 표시
                for (int y = left_cortex_y; y <= right_cortex_y; y++) {
                    plane[y][x] = (plane[y][x] | 1);
                }
            }
            else {
                plane[left_cortex_y][x] = (plane[left_cortex_y][x] | 1);
                plane[right_cortex_y][x] = (plane[right_cortex_y][x] | 1);
            }
        }

        // 길 표시 후, 현재 살펴본 사각형 영역의 좌표값을 bounds에 저장
        bounds.push_back({ {left_cortex_x, left_cortex_y}, {right_cortex_x, right_cortex_y} });
    }

    // 사각형 좌표값들을 순회하면서 이동 가능한 길들을 표시했는데
    // isInside() 를 통해 표시한 길이 각 사각형 영역 내부에 위치해있는지 확인한 후
    // 영역 내부에 있는 경우 이동 불가능한 것으로 변경한다
    for (int y = 1; y <= 100; y++) {
        for (int x = 1; x <= 100; x++) {
            if (isInside(bounds, x, y)) plane[y][x] = (plane[y][x] & 0);
        }
    }

    //// 확인용
    //for (const auto &tmp_row : plane) {
    //    for (int tmp_col : tmp_row) {
    //        printf("%d ", tmp_col);
    //    }
    //    printf("\n");
    //}
    //return 0;

    // BFS
    // dx, dy
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    // 큐
    // x, y, d 저장
    queue<pair<pair<int, int>, int>> routes;
    // 방문했는지 여부 기록
    vector<vector<bool>> visited(102, vector<bool>(102, 0));
    // 현재 시작하는 좌표도 2배로 해서 큐에 추가
    routes.push({ {characterX * 2, characterY * 2}, 0 });
    visited[characterY * 2][characterX * 2] = 1;

    // while 문 내에서 사용할 변수들
    pair<pair<int, int>, int> curr;
    int currX;
    int currY;
    int currD;
    int nextX;
    int nextY;

    while (!routes.empty()) {
        curr = routes.front();
        currX = curr.first.first;
        currY = curr.first.second;
        currD = curr.second;
        routes.pop();
        currD++;

        // 아이템 좌표까지 도착한 경우 이동거리 리턴
        if ((currX == (itemX * 2)) && (currY == (itemY * 2))) {
            return currD / 2;
        }

        for (int idx = 0; idx < 4; idx++) {
            nextX = currX + dx[idx];
            nextY = currY + dy[idx];

            // 다음에 이동할 좌표가 이동 가능한 길인 경우
            if (plane[nextY][nextX]) {
                // 방문하지 않았던 길인 경우에만 방문한 길로 표시 및 큐에 추가
                if (!visited[nextY][nextX]) {
                    visited[nextY][nextX] = 1;
                    routes.push({ {nextX, nextY}, currD });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    // 문제 예시 1
    // 예상 결과: 17
    vector<vector<int>> input_rectangles = { {1,1,7,4}, { 3,2,5,5 }, { 4,3,6,9 }, { 2,6,8,8 } };
    int c_X = 1;
    int c_Y = 3;
    int i_X = 7;
    int i_Y = 8;

    // 문제 예시 2
    // 예상 결과: 11
    //vector<vector<int>> input_rectangles = { {1,1,8,4}, { 2,2,4,9 }, { 3,6,9,8 }, { 6,3,7,7 } };
    //int c_X = 9;
    //int c_Y = 7;
    //int i_X = 6;
    //int i_Y = 1;

    // 문제 예시 3
    // 예상 결과: 9
    //vector<vector<int>> input_rectangles = { {1,1,5,7} };
    //int c_X = 1;
    //int c_Y = 1;
    //int i_X = 4;
    //int i_Y = 7;

    // 문제 예시 4
    // 예상 결과: 15
    //vector<vector<int>> input_rectangles = { {2,1,7,5}, { 6,4,10,10 } };
    //int c_X = 3;
    //int c_Y = 1;
    //int i_X = 7;
    //int i_Y = 10;

    // 문제 예시 5
    // 예상 결과: 10
    //vector<vector<int>> input_rectangles = { {2,2,5,5}, { 1,3,6,4 }, { 3,1,4,6 } };
    //int c_X = 1;
    //int c_Y = 4;
    //int i_X = 6;
    //int i_Y = 3;

    // 댓글 테케
    // 예상 결과: 8
    //vector<vector<int>> input_rectangles = { {2, 1, 3, 6}, { 4, 1, 5, 6 }, { 1, 2, 6, 3 }, { 1, 4, 6, 5 } };
    //int c_X = 3;
    //int c_Y = 2;
    //int i_X = 5;
    //int i_Y = 4;

    printf("정답: %d", solution(input_rectangles, c_X, c_Y, i_X, i_Y));
}
