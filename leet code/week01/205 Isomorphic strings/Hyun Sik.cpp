/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 배열                                    SS      WW   WW  */
/* Time Complexity   : O(N)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              : leet - 205 Isomorphic Strings           SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(std::string s, std::string t)
    {
        int lastPosS[256] = {0}; // s 문자열의 각 문자의 마지막 위치를 저장할 배열
        int lastPosT[256] = {0}; // t 문자열의 각 문자의 마지막 위치를 저장할 배열

        for (int i = 0; i < s.length(); i++) // s 문자열의 길이만큼 반복문 실행
        {
            unsigned char charS = s[i];             // s 문자열의 현재 문자를 unsigned char로 변환하여 charS에 저장
            unsigned char charT = t[i];             // t 문자열의 현재 문자를 unsigned char로 변환하여 charT에 저장
                                                    // unsigned char로 변환하는 이유는 char형은 음수값을 가질 수 있으므로 배열의 인덱스로 사용하기 위해 unsigned char로 변환
            if (lastPosS[charS] != lastPosT[charT]) // s 문자열의 현재 문자의 마지막 위치와 t 문자열의 현재 문자의 마지막 위치가 다르다면
            {
                return false; // false 리턴(서로 대응되는 문자가 다르므로)
            }

            lastPosS[charS] = i + 1; // s 문자열의 현재 문자의 마지막 위치를 i + 1로 업데이트
            lastPosT[charT] = i + 1; // t 문자열의 현재 문자의 마지막 위치를 i + 1로 업데이트
        } // i + 1 인 이유는 한 번도 나온 적 없는 문자(초기값 0)와 0번 인덱스에서 등장한 문자를 구분하기 위해서

        return true;
    }
};