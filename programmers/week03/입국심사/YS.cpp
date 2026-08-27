/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 이분탐색                                SS      WW   WW  */
/* Time Complexity   : O(m log(nT))                            SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
// 최대 시간을 구하고, 그 시간동안 몇명을 심사할 수 있는지
// n보다 크면 왼쪽으로, n보다 작으면 오른쪽으로 가서 반복
// 최소 n을 찾음
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer;
    long long left = 1;

    // 가장 느린 심사관이 n명을 전부 처리하는 경우
    long long right = (long long)*max_element(times.begin(), times.end()) * n;
    
    while(left<=right){
        long long mid = (left+right)/2; 
        long long cnt = 0;
        for(auto t:times){
            cnt += mid/t; // mid시간에 처리할 수 있는 사람 수
        }
        if(cnt>=n){ // n보다 크면 왼쪽으로 가봄, 
            answer = mid; // 지금까지 최소값 저장
            right = mid-1;
        }
        else if(cnt <n) left = mid+1; // n보다 작으면 오른쪽으로
    }
    return answer;
}

