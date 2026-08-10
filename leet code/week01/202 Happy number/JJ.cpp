/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 자료구조 : 셋                           SS      WW   WW  */
/* Time Complexity   : O(logN)                                 SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              : 1~243 사이에서 값이 계속 반복됨         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> S;
        while(1){
          //각 자리 제곱합 구하기
          int Sum = 0;
          while(n){
            Sum += pow((n % 10), 2);
            n /= 10;
          }

          if(Sum == 1) //제곱합이 1이면 true 리턴
            return true;
          
          if(S.find(Sum) != S.end()) //Sum이 이미 등장한적 있으면 (사이클 발생했다는 뜻) 1은 나올 수 없음
            return false;
          
          //Sum이 등장한 적 없으면 셋에 Sum 넣어주고
          //n은 0이므로 Sum 값으로 바꿔줌
          S.insert(Sum);
          n = Sum;
        }
    }
};

/*
int main(void)
{
  Solution sol;
  cout << sol.isHappy(19) << sol.isHappy(2);
}*/