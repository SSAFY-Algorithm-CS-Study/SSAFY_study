/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         :                                         SS      WW   WW  */
/* Time Complexity   :                                         SSSSS   WW W WW  */
/* Space Complexity  :                                            SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
초기 상태
   end
    v
    A   B   A   C   B   D
    ^
  start

  1. start == end -> end 오른쪽으로 이동
  2. v[start] == v[end] -> start 오른쪽으로 이동
  3. start ~ end 사이에 모든 종류의 보석이 등장하면 candidate에 {start, end} 추가 
  4. start가 gems 마지막에 도달하면 탐색 끝. candidate 확인.
    4-1. 제일 짧은 len(start, end) 반환
    4-2. 제일 짧은 구간이 두 개 이상이면 start가 작은 구간 반환 -> sort 함수 구현
*/

//제일 짧은 구간 반환 -> 짧은 구간 두 개 이상이면 짧은 구간 우선
bool cmp(pair<int, int> a, pair<int, int> b){
  int a_len = a.second - a.first + 1;
  int b_len = b.second - b.first + 1;

  if(a_len == b_len)
    return a.first < b.first;

  return a_len < b_len;
}

vector<int> solution(vector<string> gems) {
  vector<int> answer;
  vector<pair<int, int>> candidate;

  int start = 0, end = 0;
  auto start_iterator = gems.begin();
  

  while(start_iterator != gems.end()){
    if(start == end){
      end++;

    }
      

    
  }


    
  sort(candidate.begin(), candidate.end(), cmp);
  return {candidate[0].first , candidate[0].second};
}