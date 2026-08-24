/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : BFS                                     SS      WW   WW  */
/* Time Complexity   : O(N × M)                                SSSSS   WW W WW  */
/* Space Complexity  : O(N × M)                                   SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int y, x, dist;
    int n = maps.size()-1; // y 목적지
    int m = maps[0].size()-1; // x 목적지
    queue<pair<pair<int,int>, int>> q; // (y, x, 이동거리) 저장 큐
    maps[0][0] = 0; // 시작점은 더 못가게 0으로 바꿔줌
    q.push({{0,0},1}); // 시작점 넣어줌
    while(!q.empty()){
        y = q.front().first.first;
        x = q.front().first.second;
        dist = q.front().second;
        if(y == n &&x == m) return dist; // 목적지를 찾았으면 지금까지 이동거리 반환

        //동서남북으로 갈수있는곳이 있으면 q에 넣어줌
        if(y-1>=0 &&maps[y-1][x] == 1){
            maps[y-1][x] = 0; // 한번 간곳은 다시 가지 않음
            q.push({{y-1,x}, dist+1});
        }
        if(x-1>=0 &&maps[y][x-1] == 1){
            maps[y][x-1] = 0;
            q.push({{y,x-1}, dist+1});
        }
        if(y+1<maps.size() &&maps[y+1][x] == 1){
            maps[y+1][x] = 0;
            q.push({{y+1,x}, dist+1});
        }
        if(x+1<maps[0].size() &&maps[y][x+1] == 1){
            maps[y][x+1] = 0;
            q.push({{y,x+1}, dist+1});
        }
        q.pop(); // 맨 앞에를 pop
    }
    return -1; // 못찾으면 -1 반환
}