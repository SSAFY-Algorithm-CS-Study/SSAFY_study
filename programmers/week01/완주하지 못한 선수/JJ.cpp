/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 해시(맵)                                SS      WW   WW  */
/* Time Complexity   : O(P)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(P)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/


#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  unordered_map<string, int> um;
  string answer;

  //참가자 명단 순회하면서 맵에 [이름] : [인원] 추가
  for(const auto& s : participant)
    um[s]++;
    
  //완료 명단 순회하면서 해당 키의 값 1씩 빼주기
  for(const auto& s : completion)
    um[s]--;

  //맵에 1 이상의 값이 있다는 것은 해당 이름을 가진 사람 중 완료 못한 사람이 있다는 뜻
  for(const auto& p : um)
    if(p.second >= 1)
      answer = p.first;
  
  return answer;
}