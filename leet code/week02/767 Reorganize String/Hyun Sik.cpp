/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 우선순위 큐, 맵                         SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              : leet : 767 Reorganize String            SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> um; // 문자와 문자 수 맵으로 저장       
        for (int i = 0; i < s.length(); i++) // 문자열 길이만큼 반복문 실행
        {
            um[s[i]]++; // 문자 수 설정
        }

        priority_queue<pair<int, char>> pq; // 우선순위 큐를 통해 문자 수, 문자로 저장하고 
                                            // 문자 수로 정렬되도록 함
        for (auto& [ch, count] : um) // 맵 안의 [문자, 문자수] 만큼 반복문 실행
        {
            if ((s.length() + 1) / 2 < count) // 문자수가 문자열 길이 + 1 의 절반보다 크면
            {
                return ""; // "" 리턴(문제에서 리턴하라는 값), 이유는 절반보다 커지면 그 사이에 
                           // 문자 못 넣어서 연속되는 문자가 생김
            }
            pq.push({ count, ch }); // 리턴 안 되면 우선순위 큐에 문자수와 문자 대입
        }

		string result = ""; // 결과 문자열
        pair<int, char> prev = { 0, '#' }; // 대기할 pair<문자 수, 문자>
		while (!pq.empty()) // 우선순위 큐가 비어있지 않다면 반복문 실행
        { 
			auto [count, ch] = pq.top(); // 우선순위 큐의 top값을 저장
			pq.pop(); // 우선순위 큐의 top값 빼기

			result += ch; // 결과 문자열에 문자 추가
			count--; // 문자 수 - 1

			if (prev.first > 0) // 만약 대기열 pair의 first값인 문자 수가 0보다 크다면
            {
				pq.push(prev); // 우선순위 큐에 대입(아직 문자 수가 0이 아니고 남았기 때문에)
			}                  // 그리고 초기값이 0이라 처음에는 안 들어감

			prev = { count, ch }; // 대기열에 뺀 값 저장(다음 top 값을 문자열에 추가하고 
                                  // 전 top값이 들어가서 문자열 추가되고 이 순서로 반복)
		}

		return result; // 결과 문자열 리턴
	}
};