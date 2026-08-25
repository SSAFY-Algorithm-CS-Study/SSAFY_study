/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : BFS                                     SS      WW   WW  */
/* Time Complexity   : O(N*M)                                  SSSSS   WW W WW  */
/* Space Complexity  : O(N*M)                                     SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <iostream>
#include<vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<bool>> visited;
int di[4] = {-1, 0, 1, 0}; //상 우 하 좌 / 방향벡터
int dj[4] = {0, 1, 0, -1};

int solution(vector<vector<int> > maps)
{
    //기본 자료구조 초기화
    int N = maps.size(), M = maps[0].size();
    visited.assign(N, vector<bool>(M, false));
    queue<tuple<int, int, int>> q;
    pair<int, int> start = {0, 0}, goal = {N - 1, M - 1};

    //BFS 시작을 위한 셋업
    q.push({0, 0, 1});
    visited[0][0] = true;
    
    //BFS 수행
    while(!q.empty()){
        //현재 좌표
        pair<int, int> coor = {get<0>(q.front()), get<1>(q.front())};
        //현재 좌표의 깊이
        int depth = get<2>(q.front());
        q.pop();

        //목적지에 도달하면 depth 리턴
        if(coor.first == goal.first && coor.second == goal.second)
            return depth;
        
        //현재 좌표 기준으로 상하좌우 4방향 탐색
        for(int i = 0; i < 4; i++){
            int ni = di[i] + coor.first;
            int nj = dj[i] + coor.second;

            //다음으로 탐색할 좌표가 경계를 벗어나면
            if(ni < 0 || ni >= N || nj < 0 || nj >= M)
                continue;

            //다음으로 탐색할 좌표가 0(벽)이거나 이미 방문했으면
            if(maps[ni][nj] == 0 || visited[ni][nj])
                continue;

            visited[ni][nj] = true;
            q.push({ni, nj, depth+1}); //다음 탐색 후보지로 선정
        }
    }

    return -1;
}

