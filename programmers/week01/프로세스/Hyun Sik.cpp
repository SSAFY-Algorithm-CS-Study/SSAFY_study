/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : Brute Force(완전탐색)                   SS      WW   WW  */
/* Time Complexity   : O(N^2)                                  SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : 프로그래머스 - 프로세스                 SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;                // 정답 변수
    int index = 0;                 // 현재 인덱스
    vector<bool> isIn(100, false); // 크기가 1~100이므로 나머지는 false
    isIn[location] = true;         // 우리가 원하는 위치를 true

    while (find(isIn.begin(), isIn.end(), true) != isIn.end()) // isIn 벡터에 true가 있으면 계속 반복문 실행
    {
        int maxValue = *max_element(priorities.begin(), priorities.end()); // 가장 큰 우선순위 찾은 값

        if (priorities[index] == maxValue) // 현재 인덱스의 우선순위 값이 가장 큰 우선순위 값과 같다면(지금 인덱스의 값이 가장 큰 우선순위라면)
        {
            answer++; // 정답 변수 증가

            if (isIn[index]) // 이게 우리가 찾는 값이라면(true)
            {
                return answer; // 정답 리턴
            }

            priorities.erase(priorities.begin() + index); // 위 의문문에 해당되지 않으면 리턴을 안 하므로 계속 진행해야됨, 그래서 가장 큰 값 지우기
            isIn.erase(isIn.begin() + index);             // 마찬가지로 같은 인덱스의 값 지우기

            if (index >= priorities.size()) // 크기와 같은 값이 되면 인덱스를 넘어가므로 다시 처음으로 돌아가도록
            {
                index = 0; // 인덱스를 0으로 설정
            }
        }
        else // 아니라면 그냥 넘어가야 하므로
        {
            index++;                        // 인덱스 증가
            if (index >= priorities.size()) // 위와 마찬가지로 크기 이상 값이면 다시 처음으로 돌아가도록
            {
                index = 0; // 인덱스 0으로 설정
            }
        }
    }
    return answer; // 위에서 리턴이 안 되면 이곳에서 리턴되도록 정답 리턴
}