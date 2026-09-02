/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : Dijkstra                                SS      WW   WW  */
/* Time Complexity   : O(N²M + NM log(NM))                     SSSSS   WW W WW  */
/* Space Complexity  : O(NM)                                      SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include <string>
using namespace std;

const int INF = 1e9;

int main() {
	int N, M, starty, startx, endy, endx;
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(M));
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			cin >> v[i][j];
			if (v[i][j] == 2) { // 출발점 저장
				starty = i;
				startx = j;
			}
			else if (v[i][j] == 3) { // 도착지 저장
				endy = i;
				endx = j;
			}
		}
	}
	vector<vector<int>> dist(N, vector<int>(M, INF)); // 출발부터 인덱스까지의 이동거리 저장
	priority_queue<
		tuple<int, int, int>,
		vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>>
	>pq; // {이동거리, y, x} 저장

	pq.push({ 0, starty, startx }); // 출발지 넣음
	dist[starty][startx] = 0;
	
	int dy[4] = {-1,1,0,0};
	int dx[4] = {0,0,-1,1};
	while (!pq.empty()) {
		auto [nowDist, nowy, nowx] = pq.top();
		pq.pop();
		if (nowDist > dist[nowy][nowx])
			continue;

		for (int i = 0;i < 2;i++) { // 상하로 움직일 때
			int ny = nowy;
			int nx = nowx;
			int weight = 0;
			while (1) { // 가장 가까운 땅 찾기
				ny += dy[i];
				nx += dx[i];
				weight++; // 상하로 한번 움직일때 1씩 증가
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) break;
				if (v[ny][nx] != 0) break;	 			
			}
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue; // 인덱스 범위가 안맞으면 넘어감
			int newDist = max(nowDist, weight); // 움직였을때의 게이지 최대값
			if (dist[ny][nx] > newDist) {
				dist[ny][nx] = newDist;
				pq.push({ newDist, ny, nx });
			}

		}
		for (int i = 2;i < 4;i++) { // 좌우로 움직일 때
			int ny = nowy +dy[i];
			int nx = nowx+dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;// 인덱스 범위가 안맞으면 넘어감
			if (v[ny][nx] == 0)continue; // 땅이 아니면 넘어감
			if (dist[ny][nx] > nowDist ) {
				dist[ny][nx] = nowDist;
				pq.push({nowDist, ny, nx});
			}

		}
	}
	cout << dist[endy][endx];
	return 0;
}