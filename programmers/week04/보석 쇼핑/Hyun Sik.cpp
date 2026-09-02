/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : 투포인터, 슬라이딩 윈도우               SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(K)                                       SS   WWW WWW  */
/* Note              : programmers - 보석 쇼핑                 SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer; // 정답 구간의 시작 위치와 끝 위치를 저장할 벡터
    unordered_set<string> us; // 전체 보석의 종류를 중복 없이 저장할 set
    unordered_map<string, int> um; // 현재 탐색 구간에 존재하는 보석별 개수를 저장할 해시맵
    for (int i = 0; i < gems.size(); i++) // 전체 보석 수만큼 반복문 실행
    {
        us.insert(gems[i]); // set에 각 보석을 대입하여 보석의 종류 확인    
    }

    int eachOneCount = us.size(); // 전체 보석 종류의 개수 저장
    int left = 0; // 현재 탐색 구간의 왼쪽 포인터
    int answerLeft = 0; // 현재까지 찾은 최적 구간의 시작 위치
    int answerRight = gems.size() - 1; // 현재까지 찾은 최적 구간의 끝 위치
                                       // 처음에는 전체 구간을 정답 후보로 설정
    for (int right = 0; right < gems.size(); right++) // right 포인터를 오른쪽으로 이동시키면서 
                                                      // 탐색 구간 확장
    {
        um[gems[right]]++; // 새롭게 구간에 포함된 보석의 개수를 1 증가

        while (um.size() == eachOneCount) // 현재 구간에 모든 종류의 보석이 포함되어 있는 동안
        {                                 // left를 이동시키면서 구간을 최대한 축소
            if (right - left < answerRight - answerLeft)  // 현재 구간이 기존 정답 구간보다 짧은 경우
            {
                answerLeft = left; // 현재 구간의 시작 위치를 정답으로 저장
                answerRight = right; // 현재 구간의 끝 위치를 정답으로 저장
            }

            um[gems[left]]--; // left가 가리키는 보석을 구간에서 제외하므로 개수를 1 감소

            if (um[gems[left]] == 0) // 해당 보석의 개수가 0이 되었다면
            {                        // 현재 구간에 해당 종류의 보석이 존재하지 않으므로
                um.erase(gems[left]); // 해시맵에서 해당 보석 종류를 제거
            }

            left++; // 왼쪽 포인터를 오른쪽으로 한 칸 이동하여 구간 축소
        }        
    }
    answer.push_back(answerLeft + 1); // 문제에서 보석 번호가 1부터 시작하므로 시작 인덱스에 1을 더해 저장
    answer.push_back(answerRight + 1); // 끝 인덱스 역시 1부터 시작하도록 1을 더해 저장
    return answer; // 가장 짧은 구간의 시작 번호와 끝 번호를 포함한 정답 벡터 리턴
}