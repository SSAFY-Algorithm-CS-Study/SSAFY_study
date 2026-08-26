/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 비트마스킹, 재귀                        SS      WW   WW  */
/* Time Complexity   : O(2^N * L)                              SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : leetcode - 1239 Maximum Length of a …   SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int answer = 0; // 정답 정수

    void getLength(int index, int used, int length, vector<string>& arr)
    {
        answer = max(answer, length); // 정답과 길이 중 더 큰 값을 정답으로
        for (int i = index; i < arr.size(); i++) // 현재 인덱스부터 벡터의 크기까지 반복문 실행
        {
            int mask = 0; // 비트 연산할 마스크 정수
            bool canUse = true; // 문자열 내부에 중복 문자가 있으면 false

            for (char character : arr[i]) // 뮨자열의 알파벳 수 만큼 반복문 실행
            {
                int bit = 1 << (character - 'a'); // 변수로 현재 알파벳을 비트로 표현
                                                  // 예: "a" -> 000...0001
                                                  //     "b" -> 000...0010

                if (mask & bit) // 현재 문자열에서 이미 등장한 문자라면 같은 문자가 중복해서 존재하므로
                {
                    canUse = false; // 이미 사용해서 사용 불가능하므로 false
                    break; // 불가능하니 바로 break;
                }

                mask |= bit; // 현재 문자의 비트를 mask에 추가하는데
                             // OR 연산을 사용하면 기존에 저장된 비트는 유지하면서
                             // 현재 문자의 비트만 1로 만들 수 있음 
            }

            if (!canUse) // 문자열 내부에 중복 문자가 있었다면           
            {
                continue; // 해당 문자열은 사용할 수 없으므로 다음 문자열로 넘어감
            }

            if (used & mask) // 지금까지 선택한 문자열들의 문자(used)와
                             // 현재 문자열의 문자(mask)가 겹치는지 확인
                             // 겹치는 비트가 하나라도 있다면
                             // 같은 알파벳을 이미 사용하고 있다는 의미
            {
                continue; // 그렇다면 다음 문자열로 넘어감
            }
                
            getLength(i + 1, used | mask, length + arr[i].length(), arr); 
            // 현재 문자열을 선택한 상태로 다음 문자열을 탐색
            // i + 1 : 같은 문자열을 다시 선택하지 않도록 다음 인덱스로 이동
            // used | mask : 기존에 사용한 문자 + 현재 문자열의 문자
            // length + arr[i].length() : 현재 문자열의 길이를 정답 후보에 추가
        }
    }

    int maxLength(vector<string>& arr) {
        getLength(0, 0, 0, arr); // 가장 긴 길이 구하는 비트마스크 재귀함수 실행

        return answer; // 정답(가장 긴 문자열 길이) 정수 리턴
    }
};