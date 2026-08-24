/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 그리디, 투포인터                        SS      WW   WW  */
/* Time Complexity   : O(N log N)                              SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : 프로그래머스 - 구명보트                 SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0; // 정답 정수

    sort(people.begin(), people.end(), greater<int>()); // 내림차순으로 벡터 정렬

    int left = 0; // 왼쪽 끝 시작 인덱스
    int right = people.size() - 1; // 오른쪽 끝 시작 인덱스 
    while (left <= right) // 인덱스가 이 조건을 만족할 때 반복문 실행
    {
        if (people[left] + people[right] <= limit) // 만약 현재 가장 큰 값과 가장 작은 값의 합이 무게 제한 값보다 작으면
        {
            right--; // 둘 다 탈 수 있으므로 오른쪽 인덱스 줄이기(최대 둘까지 탑승 가능하므로 이것만 판단)
        }

        left++; // 한명 혹은 두명 모두 가장 큰 값의 사람은 타므로 인덱스 증가
        answer++; // 한번 탔으므로 정답 증가
    }

    return answer; // 정답 리턴
}