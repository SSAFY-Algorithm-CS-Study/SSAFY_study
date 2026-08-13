/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 재귀                                    SS      WW   WW  */
/* Time Complexity   : O(2^n)                                  SSSSS   WW W WW  */
/* Space Complexity  : O(n)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
    하노이의 탑 동작 순서는 크게 3가지로 나눌 수 있다
    n개의 원판이 있을 때 (초기 상태)
    1. n-1개의 원판을 경유 막대기로 옮긴다 (A막대 -> B막대)
    2. n번째의 원판 1개를 목적지로 옮긴다 (A막대 -> C막대)
    3. 경유 막대기에 있는 n-1개의 원판을 목적지로 옮긴다 (B막대 -> C막대)

*/
void hanoi(const int& n, const int& origin, const int& dest, const int& via, vector<vector<int>>& answer)
{
    vector<int> temp;
    // 탈출조건 : 이동할 원판이 하나일 때는 목적지로 바로 옮기면 된다.
    if(n == 1){
        temp.push_back(origin);
        temp.push_back(dest);
        answer.push_back(temp);
        return ;
    }

    // origin 위의 n-1개의 원판을 경유 막대기로 옮긴다
    hanoi(n-1, origin, via, dest, answer);

    // n번째의 가장 큰 원판을 목적지로 옮긴다
    temp.push_back(origin);
    temp.push_back(dest);
    answer.push_back(temp);

    // n-1개의 원판을 목적지로 옮긴다
    hanoi(n-1, via, dest, origin, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, 2, answer);
    return answer;
}

int main(void)
{
    vector<vector<int>> result = solution(2);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
}