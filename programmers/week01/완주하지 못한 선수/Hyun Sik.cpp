/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 맵(해시)                                SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : 프로그래머스 - 완주하지 못한 선수       SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> m; // 참가자 이름과 참가수 수를 저장하는 맵 생성(정렬 필요없으므로 unordered_map 사용)

    for (const string &name : participant) // 참가자 이름을 하나씩 꺼내서
    {
        m[name]++; // 참가자수 수 증가
    }

    for (const string &name : completion) // 완주자 이름을 하나씩 꺼내서
    {
        m[name]--; // 완주자이므로 참가자 수 감소
    }

    for (const string &name : participant) // 진행 후 참가자 이름을 하나씩 꺼내서
    {
        if (m[name] > 0) // 참가자 수가 0보다 크다면 완주하지 못한 선수이므로
        {
            return name; // 해당 이름 리턴
        }
    }

    return "";
}