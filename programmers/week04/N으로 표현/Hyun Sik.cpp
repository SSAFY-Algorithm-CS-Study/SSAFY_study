/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : DP                                      SS      WW   WW  */
/* Time Complexity   : O(8^2 * K^2)                            SSSSS   WW W WW  */
/* Space Complexity  : O(8 * K)                                   SS   WWW WWW  */
/* Note              : programmers - N으로 표현                SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    vector<unordered_set<int>> dp(9); // 숫자 N을 i개 사용해서 만들 수 있는 모든 값
                                      // N이 1 이상 9 이하이므로 9로 크기 지정

    int repeated = 0; // N, NN, NNN과 같이 N을 이어 붙여 만든 숫자
    for (int i = 1; i <= 8; i++) // 문제에서 최솟값이 8보다 크면 -1을 return 이므로 1~8 반복문 실행 
    {
        repeated = repeated * 10 + N; // N을 i개 이어 붙인 숫자를 생성
                                      // 예: N = 5일 때 5 -> 55 -> 555 ...
        dp[i].insert(repeated); // N을 i개 이어 붙인 숫자도 N을 i개 사용해서 만들 수 있으므로 저장
        for (int j = 1; j < i; j++) // N을 i개 사용하는 경우를
                                    // j개를 사용한 결과와 (i-j)개를 사용한 결과로 나누어 조합
        {
            for (int a : dp[j]) // N을 j개 사용해서 만들 수 있는 모든 값으로 반복문 실행
            {
                for (int b : dp[i - j]) // N을 (i-j)개 사용해서 만들 수 있는 모든 값으로 반복문 실행
                {
                    dp[i].insert(a + b); // 두 값을 더한 결과 대입
                    dp[i].insert(a - b); // 두 값을 뺀 결과 대입
                    dp[i].insert(a * b); // 두 값을 곱한 결과 대입

                    if (b != 0) // 0으로 나눌 수 없으므로 b가 0이 아닌 경우에만 나눗셈 실행
                    {
                        dp[i].insert(a / b); // 두 값을 나눈 결과 대입
                    }                        
                }
            }
        }

        if (dp[i].count(number)) // N을 i개 사용해서 만든 값들 중 목표 숫자 number가 존재한다면
        {
            return i; // // 처음 발견된 i가 N의 최소 사용 횟수이므로 i 리턴
        }           
    }

    return -1; // 문제 조건이 최솟값이 8보다 크면 -1을 return 합니다. 이므로 -1 리턴
}