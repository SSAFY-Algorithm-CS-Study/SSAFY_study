/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 시뮬레이션                              SS      WW   WW  */
/* Time Complexity   : O(N^2)                                  SSSSS   WW W WW  */
/* Space Complexity  : O(N^2)                                     SS   WWW WWW  */
/* Note              : 배열 회전 빈출이므로 공식 외우기        SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;
/*
회전 공식(시계 방향 회전)
90 : temp_arr[i][j] = arr[N - 1 - j][i]
180 : temp_arr[i][j] = arr[N - 1 - i][N - 1 - j]
270 : temp_arr[i][j] = arr[j][N - 1 - i]

    // 90도 회전 예
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            temp_arr[i][j] = arr[N - j -1][i];
*/
vector<vector<int>> rotate(vector<vector<int>>& v, const vector<int>& spinInfo)
{
  int startI = spinInfo[0]; //회전 좌표
  int startJ = spinInfo[1];
  int size = spinInfo[2]; //회전시킬 크기
  int angle = spinInfo[3]; //반시계 회전. 1이면 90, 2이면 180, 3이면 270

  int N = v[0].size();
  vector<vector<int>> temp = v;
  
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){

      //시작점 (startI,startJ)를 기준으로 size * size 크기의 2차원 배열을 회전시킨다고 보면 된다. (startI, startJ)를 기준점(0,0)으로 보고 공식 적용
      if(angle == 1) //반시계 90도 (= 시계 270도)
        temp[startI + i][startJ + j] = v[startI + j][startJ + size - 1 - i];
      

      else if(angle == 2) //반시계 180도
        temp[startI + i][startJ + j] = v[startI + size - 1 - i][startJ + size - 1 - j];
      

      else if(angle == 3) //반시계 270도
        temp[startI + i][startJ + j] = v[startI + size - 1 - j][startJ + i];
      
    }
  }

  return temp;
}

int main(void)
{
  //입력
  int N; cin >> N;
  vector<vector<int>> v(N, vector<int>(N,0));

  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      cin >> v[i][j];
  
  int Q; cin >> Q;
  vector<vector<int>> spinInfo(Q, vector<int>(4,0));

  for(int i = 0; i < Q; i++)
    for(int j = 0; j < 4; j++)
      cin >> spinInfo[i][j];

  ///////////////////////////////////////////////////////

  //spin 계산
  for(int i = 0; i < Q; i++)
    v = rotate(v, spinInfo[i]);

  ///////////////////////////////////////////////////////

  //출력
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << v[i][j] << ' ';
      
    }
    cout << '\n';
  }
}