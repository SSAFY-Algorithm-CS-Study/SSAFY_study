/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : 시뮬레이션, BFS                         SS      WW   WW  */
/* Time Complexity   : O(NMlogN)                               SSSSS   WW W WW  */
/* Space Complexity  : O(NM)                                      SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int N,M;
vector<vector<int>> Map;
pair<int, int> start, goal;
int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};

//Map[i][j]가 땅인지 판별(땅에서만 좌우로 이동 가능)
bool isGround(int i, int j)
{
    return 0 != Map[i][j];
}

//start에서 시작해 limit을 초과하기 전에 보석을 찾을 수 있는지 확인하는 함수
/*
현재 좌표를 기준으로 상하좌우 탐색 (좌우로는 한 칸, 상하로는 limit 범위 내에서 처음으로 닿는 땅)
방문하지 않았으면서 처음으로 닿는 땅을 큐에 넣으면서 BFS 진행
BFS를 진행하며 목표 지점에 도달하면 true 리턴
*/
bool check(int limit, int startI, int startJ)
{
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    q.push({startI, startJ});
    visited[startI][startJ] = true;

    //BFS
    //현재 위치에서 이동할 수 있는 좌우 좌표 넣은 후, 수직 이동하면서 
    while(!q.empty()){
        auto [currI, currJ] = q.front();
        q.pop();

        //목표 지점에 도달하면 리턴
        if(currI == goal.first && currJ == goal.second)
            return true;

        //현 위치에서 좌우로 한 칸씩 움직여 가며 탐색 진행
        for(int dir = 0; dir < 2; dir++){
            int ni = currI;
            int nj = currJ + dj[dir];

            //범위 검사
            if(nj < 0 || nj >= M)
                continue;

            //땅이 아니면 이동 불가
            if(!isGround(ni, nj))
                continue;
            
            //이미 방문한 곳은 다시 큐에 넣을 필요 없음
            if(visited[ni][nj])
                continue;
            
            visited[ni][nj] = true;
            q.push({ni, nj});
        }


        //수직이동
        for(int dir = 2; dir < 4; dir++){
            for(int distance = 1; distance <= limit; distance++){
                int ni = currI + di[dir] * distance; //현 좌표에서 상하로 limit에 닿을 때까지 이동
                int nj = currJ;

                //범위 검사
                if(ni < 0 || ni >= N) 
                    break;

                //땅이고 방문하지 않은 곳이면 큐에 추가 후 탐색 종료 
                //새로 추가된 땅 위에 또 다른 땅이 있더라도 당장 새롭게 만난 땅 하나만 추가하고 탐색 끝냄(나중에 결국 방문하게 됨)
                /*
                --------- C
                ---       B
                ------    A 

                A -> B -> C 이동이 아닌 
                A -> B 후 나중에 B -> C 되게끔
                */
                if(isGround(ni, nj)){
                    if(!visited[ni][nj]){
                        visited[ni][nj] = true;
                        q.push({ni, nj});
                    }

                    break;
                }
            }
        }
    }
    return false;
}

int solve()
{
    // 이분탐색
    int left = 0, right = N; //Limit 범위
    int answer = INT_MAX;

    while(left <= right){
        int mid = left + (right - left) / 2;

        //현재 limit값으로 목표에 도달 가능하면 anwer값 갱신 후 limit 더 낮워보기
        //start : 시작점. mid : 임의의 limit값
        if(check(mid, start.first, start.second)){ 
            answer = mid;
            right = mid - 1;
        }

        else //불가능하면 limit 값 늘리기
            left = mid + 1;
    }

    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    Map.assign(N, vector<int>(M,0)); //테스트 케이스 여러 개이므로 매 케이스마다 초기화해주기

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int temp; cin >> temp;
            Map[i][j] = temp;
            if(temp == 2)
                start = {i, j}; //시작점 등록
            else if(temp == 3)
                goal = {i, j}; //도착점 등록
        }
    }

    int answer = solve();
    cout << answer << '\n';
}