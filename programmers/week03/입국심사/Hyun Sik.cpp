/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 이분탐색                                SS      WW   WW  */
/* Time Complexity   : O(T log(M * N))                         SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              : 프로그래머스 - 입국심사                 SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1; // 가장 왼쪽(심사하는데 걸리는 최소 시간 후보) 
    long long right = (long long)*max_element(times.begin(), times.end()) * n;
                        // 가장 오른쪽(심사하는데 걸리는 최대 시간)
                        // 벡터에 있는 가장 오래 걸리는 심사관의 시간 * 심사 받는 사람 수)
    while (left <= right) // 탐색할 시간의 범위가 남아있는 동안 반복 
    {                    
        long long mid = left + (right-left) / 2; // left와 right 사이의 중앙값
        long long count = 0; // mid 시간 동안 심사할 수 있는 사람 수 
        for (int time : times) // 각 심사관의 심사 시간을 하나씩 확인  
        {                      
            count += mid / time; // mid 시간 동안 해당 심사관이 심사할 수 있는 사람 수
        }

        if (count >= n) // 만약 구한 심사받은 사람 수가 총 사람 수 보다 크거나 같다면 
        {
            right = mid - 1; // 중앙값의 왼쪽 값 즉 중앙값부터는 원하는 값이 없으므로
                             // 그보다 왼쪽 값을 오른쪽에 대입
        }
        else
        {
            left = mid + 1; // 반대면 중앙값보다 오른쪽값을 왼쪽에 대입
        }
    }

    return left; // 왼쪽 값을 리턴(가장 적게 걸리는 최솟값을 정답으로 해야 하므로 left)
}