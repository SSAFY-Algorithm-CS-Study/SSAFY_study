#include <iostream>
#include <vector>

using namespace std;

// [메인 아이디어]
// 
// 땅인 칸에서는(=1) 좌우, 상하 이동 모두 가능
// 공중 칸에서는(=0) 상하 이동만 가능
// 
// 상하 이동 시에는 필요 게이지를 따로 기록할 것(=limit, min_limit)
// 최단 거리를 탐색하는 것이 아니므로, 전체를 탐색할 수 있는 DFS로 정함
// 경로 탐색 시, 지나온 길을 기록하되, 재귀로 구현할 것이므로 복구 로직에서 지나온 길 되돌리는 것 추가
// 

// 맵
vector<vector<int>> playmap;

// 맵의 행, 열
int N, M;

// 방향벡터
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// 좌표
struct Pos {
	int x;
	int y;
};

// 최소 상하 이동 거리
int min_limit;

// 탐색
// 아직 구현 전이거나 완벽히 고려하지 못한 케이스
// 
// 1. 공중에서 땅으로 착지한 경우 처리 -> 최소 상하 이동 거리 갱신
// 2. 도착점에 도착한 경우 처리 -> 실제로 이동 가능한 경로임을 확인하고 그에 맞춰 처리
// 
int movement(Pos curr_pos, int d, vector<vector<int>>& visited) {
	int x = curr_pos.x;
	int y = curr_pos.y;
	int nx, ny;

	for (int dir_idx = 0; dir_idx < 4; dir_idx++) {
		// 공중에 위치한 경우 x 이동 건너뛰기
		if (playmap[y][x] == 0 && (dir_idx == 0 || dir_idx == 1)) continue;
		// 상하 이동일 경우 d +1
		if (dy[dir_idx] != 0) d++;

		// 이동 후 좌표
		nx = x + dx[dir_idx];
		ny = y + dy[dir_idx];

		// 범위 벗어난 경우 건너뛰기
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		// 이미 방문한 경우 건너뛰기
		if (visited[ny][nx]) continue;
		// 방문하지 않은 경우 기록
		else visited[ny][nx] = 1;
		// 공중에서 땅에 착지한 경우 d 리턴
		if (!playmap[y][x] && playmap[ny][nx]) return d;

		// DFS
		d = movement({ nx, ny }, d, visited);
		if (min_limit > d) min_limit = d;
		// 복구 (백트래킹?)
		visited[ny][nx] = 0;
	}

	return d;
}

int main() {
	cin >> N >> M;
	min_limit = N;

	// 주요 좌표 (x, y)
	Pos start_pos = { 0, 0 };
	Pos end_pos = { 0, 0 };

	// 방문 기록
	vector<vector<int>> visited(N, vector<int>(M, 0));

	// playmap 입력 위한 변수
	vector<int> temp_row;
	int temp_elem;
	// playmap 입력
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			cin >> temp_elem;
			// 시작점인 경우 start_pos에 저장 후 1로 변경
			if (temp_elem == 2) {
				start_pos.x = col;
				start_pos.y = row;
				temp_elem = 1;
			}
			// 도착점인 경우 end_pos에 저장 후 1로 변경
			else if (temp_elem == 3) {
				end_pos.x = col;
				end_pos.y = row;
				temp_elem = 1;
			}
			temp_row.push_back(temp_elem);
		}
		playmap.push_back(temp_row);
		// 행 하나 넣은 후 비우기
		temp_row.clear();
	}

	// 입력 확인
	cout << "시작 좌표 (행, 열): " << start_pos.y << ", " << start_pos.x << "\n";
	cout << "목표 좌표 (행, 열): " << end_pos.y << ", " << end_pos.x << "\n";
	cout << "전체 맵\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << playmap[i][j] << " ";
		}
		cout << "\n";
	}

	// 탐색 시작
	movement(start_pos, 0, visited);

	// 출력
	cout << min_limit;
}