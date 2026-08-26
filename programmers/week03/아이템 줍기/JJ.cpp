/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         :                                         SS      WW   WW  */
/* Time Complexity   :                                         SSSSS   WW W WW  */
/* Space Complexity  :                                            SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<int>> board(250, vector<int>(250,0));
vector<vector<bool>> visited(250, vector<bool>(250, false));
pair<int, int> start, goal;

int di[4] = {-1, 0, 1, 0}; //방향벡터
int dj[4] = {0, 1, 0, -1};

//depth를 저장한 목적지까지의 단순 BFS
int BFS()
{
    queue<tuple<int, int, int>> q;
    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = true;

    while(!q.empty()){
        int currI = get<0>(q.front()), currJ = get<1>(q.front()), depth = get<2>(q.front());
        q.pop();

        if(currI == goal.first && currJ == goal.second)
            return depth;
        
            
        for(int dir = 0; dir < 4; dir++){
            int ni = currI + di[dir];
            int nj = currJ + dj[dir];


            if(ni < 0 || ni >= 250 || nj < 0 || nj >= 250)
                continue;
            
            if(visited[ni][nj] || board[ni][nj] == 0)
                continue;
            
            q.push({ni, nj, depth + 1});
            visited[ni][nj] = true;
        }

    }
    return -1;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    board.assign(250, vector<int>(250, 0));
    visited.assign(250, vector<bool>(250, false));

    int answer = 0;
    //4배 확대
    characterX *= 4; characterY *= 4;
    itemX *= 4; itemY *= 4;
    start = {characterY, characterX};
    goal = {itemY, itemX};
    

    int x1, x2, y1, y2;

    //직사각형을 보드에 입력
    for(int i = 0; i < rectangle.size(); i++){

        //4배 늘려주기
        for(int j = 0; j < rectangle[0].size(); j++)
            rectangle[i][j] *= 4; 

        x1 = rectangle[i][0]; x2 = rectangle[i][2];
        y1 = rectangle[i][1]; y2 = rectangle[i][3];

        for(int y = y1; y <= y2; y++){
            for(int x = x1; x <= x2; x++){
                board[y][x] = 1;
            }
        }
    }
    
    
    //직사각형 내부는 0으로 채우기 (직사각형끼리 겹칠 경우 한 직사각형 내부에 1이 존재할 수도 있음)
    for(int i = 0; i < rectangle.size(); i++){
        x1 = rectangle[i][0]; x2 = rectangle[i][2];
        y1 = rectangle[i][1]; y2 = rectangle[i][3];

        for(int y = y1 + 1; y < y2; y++){
            for(int x = x1 + 1; x < x2; x++){
                board[y][x] = 0;
            }
        }
    }

    //BFS
    answer = BFS();

    
    return answer / 4;
}