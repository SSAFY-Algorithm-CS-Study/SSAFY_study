/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : Brute Force(완전탐색)                   SS      WW   WW  */
/* Time Complexity   : O(N^2)                                  SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : 프로그래머스 - 주식가격                 SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector> // 벡터 활용
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;                     // 정답 벡터
    for (int i = 0; i < prices.size(); i++) // 현재 인덱스(prices의 크기까지)
    {
        int countSecond = 0;                        // 몇 초까지 가격이 떨어지지 않는지의 값
        for (int j = i + 1; j < prices.size(); j++) // 비교할 인덱스(비교해야 하므로 +1부터, prices의 크기까지)
        {
            countSecond++; // 일단 무조건 1 증가, 이유는 당장 다음 인덱스의 값이 현재보다 작아도 1초간 떨어지지 않는다고 보기 때문
            if (prices[i] > prices[j])
            {
                break; // 비교 인덱스값이 떨어진다면 더 볼 필요 없으므로 바로 현재 반복문 종료
            }
        }
        answer.push_back(countSecond); // 위 과정을 통해 구한 몇 초까지 가격이 떨어지지 않는지 저장한 변수 answer 벡터에 대입
    }
    return answer;
}