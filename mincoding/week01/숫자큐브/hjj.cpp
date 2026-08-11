#include <iostream>
#include <vector>

using namespace std;

// 회전 계산
// 1  2  3  4
// 5  6  7  8
// 9  10 11 12
// 13 14 15 16
// 
// 반시계 90도
// 4 8 12 16
// 3 7 11 15
// 2 6 10 14
// 1 5 9  13
//
// x축 상으로 1, 2, 3, 4 이던게 y 축으로 4, 3, 2, 1 로 역순 정렬
// 각 축 별로 역순 정렬시키면 원하는 모양을 얻을 수 있다? -> 아님. 다른 규칙
// 
// 7  : (1, 2) -> (1, 1) ((4 - 1) - 2, 1)
// 10 : (2, 1) -> (2, 2) 
// 3  : (0, 2) -> (1, 0) ((4 - 1) - 2, 0)
// 
// 규칙: 회전 중심(cx, cy)을 기준으로 (dx, dy) -> (-dy, dx)
// dx = x - cx, dy = y - cy
// 위 식을 변환하면 (x - cx, y - cy) -> (cy - y, x - cx)
// 더 변환하면 (x - cx, y - cy) + (cx, cy) -> (cy - y, x - cx) + (cx, cy)
// (x, y) -> (-y + cx + cy, x - (cx - cy))
// 
// vector 기준으로는 (d_row, d_col) -> (d_col, -d_row)
// 회전 중심은 ((rot_size - 1) / 2, (rot_size - 1) / 2)
// d_row = row - ((rot_size - 1) / 2)
// d_col = col - ((rot_size - 1) / 2)
// (row - ((rot_size - 1) / 2), col - ((rot_size - 1) / 2)) -> (col - ((rot_size - 1) / 2), -row + ((rot_size - 1) / 2))
// (row, col) -> (col, -row + (rot_size - 1))
// 

int main() {
	vector<vector<int>> cube;
	vector<int> cube_line;

	// cube 크기
	int n;
	// cube line에 요소 넣기 위한 임시 변수
	int a;

	// cube 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			cube_line.push_back(a);
		}
		cube.push_back(cube_line);
		cube_line.clear();
	}

	// 커맨드 횟수
	int cmd_cnt;
	cin >> cmd_cnt;

	// 커맨드에서 지시하는 index, 회전 대상 크기(rot_size X rot_size 가 회전 대상), 회전수
	int row, col, rot_size, rot_cnt;

	// 회전 결과를 저장할 벡터
	// pair<int, int>는 각각 인덱스, 값
	vector<pair<pair<int, int>, int>> rot_result;
	// rot_result 의 각 요소 저장할 변수
	pair<pair<int, int>, int> rot_result_elem;

	// 커맨드 별로 실행
	for (int cmd_idx = 1; cmd_idx <= cmd_cnt; cmd_idx++) {
		cin >> row >> col >> rot_size >> rot_cnt;
		// row, col 좌표는 항상 회전 대상의 좌측 상단
		// 회전 index 기준 각 거리: row_idx - row, col_idx - col
		// 회전수 만큼 반복
		for (int r = 0; r < rot_cnt; r++) {
			for (int row_i = rot_size - 1; row_i >= 0; row_i--) {
				for (int col_i = 0; col_i < rot_size; col_i++) {
					rot_result.push_back({ { row - col_i + (rot_size - 1) , col + row_i },  cube[row + row_i][col + col_i] });
				}
			}
			while (!rot_result.empty()) {
				rot_result_elem = rot_result.back();
				rot_result.pop_back();
				cube[rot_result_elem.first.first][rot_result_elem.first.second] = rot_result_elem.second;
			}
		}
	}

	// cube 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << cube[i][j] << " ";
		}
		cout << endl;
	}
}