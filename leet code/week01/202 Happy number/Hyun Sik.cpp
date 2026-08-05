/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 셋                                      SS      WW   WW  */
/* Time Complexity   : O(logN)                                 SSSSS   WW W WW  */
/* Space Complexity  : O(logN)                                    SS   WWW WWW  */
/* Note              : leet - 202 Happy Number                 SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        set<int> s; // 수를 저장할 set 생성(중복 방지)
        while (n != 1)
        {
            if (s.find(n) != s.end()) // set에 이미 존재하는 값이라면 무한루프이므로
            {
                return false; // false 리턴
            }

            s.insert(n); // set에 값 추가

            string str = to_string(n);             // int형 n을 string형으로 변환하여 각 자리수를 구하기 위해 string형으로 변환
            int newN = 0;                          // 각 자리수의 제곱을 더한 값을 저장할 변수
            for (int i = 0; i < str.length(); i++) // 각 자리수의 제곱을 더한 값을 구하기 위해 string 자릿수까지 반복문
            {
                int num = str[i] - '0'; // char형인 str[i]를 int형으로 변환하기 위해 '0'을 빼줌
                int square = num * num; // 제곱하여 square에 저장
                newN += square;         // 각 자리수의 제곱을 더한 값을 newN에 더함
            }

            n = newN; // 각 자리수의 제곱을 더한 값을 n에 대입하여 다음 반복문에서 사용
        }

        return true; // 무한 루프가 아니라면 true 리턴(1이 되는 경우)
    }
};