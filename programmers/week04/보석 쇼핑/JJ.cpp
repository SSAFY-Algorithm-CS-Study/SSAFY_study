/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : 투포인터 및 해시 자료구조               SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(K)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
초기 상태
   right
    v
    A   B   A   C   B   D
    ^
   left

  1. [left, right]에 보석 4종류가 안되면 right 오른쪽으로 이동 (구간을 늘려서 종류를 늘리기 위함)
  2. [left, right]에 4종류가 되면 left를 오른쪽으로 이동(구간을 줄여서 구간 최솟값을 구하기 위함)
  3. left, right gems.end()에 도달하면 종료

  구간 보석 종류 관리 방식?
  1. 구간 사이 보석 종류가 4종류가 되면 candidate에 저장. (구간 크기를 오름차순으로 저장하는 우선순위큐)
  2. unordered_map 사용. {보석 이름 : 개수} 형태로 관리. 개수가 0이 되면 erase해 .size != 4이도록.

  -> 우선순위큐는 넣을 때마다 log K만큼의 비용이 들고 map의 size는 O(1). -> map 사용
*/

vector<int> solution(vector<string> gems) {
  
  //보석 종류 수
  unordered_set<string> type(gems.begin(), gems.end());
  int num_of_type = type.size();

  //투포인터를 위한 초기화
  pair<int, int> min_distance = {0, INT_MAX};
  unordered_map<string, int> um;
  int left = 0, right = 0;
  um[gems[right]]++;

  while(1){
    if(um.size() == num_of_type){ //4종류면 left 이동
      //4종류가 되었을 때, 구간 크기 비교를 해서 답 갱신
      if(right - left < min_distance.second - min_distance.first)
        min_distance = {left, right};
    
      //개수 줄인 후 이동
      um[gems[left]]--;

      if(um[gems[left]] == 0) //0개가 되면 map에서 삭제
        um.erase(gems[left]); 

      left++;
    } 

    else{ //4종류 안되면 right 이동
      right++;

      //right가 gems.size()가 됐다면 right가 gems 마지막 원소를 가리켰을 때도 4종류가 안되어 right++로 gems.size()가 되었음
      //더 탐색하는 것이 의미가 없어지므로 반복문 탈출
      if(right == gems.size())
        break;

      um[gems[right]]++;
    }
  }

  //1-based index이므로 +1 해주기
  return {min_distance.first + 1 , min_distance.second + 1};
}