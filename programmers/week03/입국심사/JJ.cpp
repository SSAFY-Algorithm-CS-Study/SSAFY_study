/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : 이진탐 색(파라매트릭 서치)              SS      WW   WW  */
/* Time Complexity   : O(mlogm + mlog(n*T))                    SSSSS   WW W WW  */
/* Space Complexity  : O(logm)                                    SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
심사를 받는 인원이 10억명. O(N)으로 처리하게 되면 타임오버 발생 -> O(logN)으로 처리해야함 

파라매트릭 서치 : 최적화 문제를 이진 탐색을 이용하여 결정 문제로 바꾸는 것
    최적화 문제 : 어떤 조건을 만족하는 값의 최솟값이나 최댓값을 구하는 문제 
    결정 문제   : 특정 값이 조건을 만족하는지 Yes / No로 대답할 수 있는 문제
*/
long long solution(int n, vector<int> times) {
    long long answer = 0;
    //mid 설정. 이 mid시간 내에 심사완료 가능? -> 어떻게 체크? 
    //최종 완료 시간은 언제나 심사관 소요 시간의 배수
    //후보 시간 / 소요시간 몫들의 합 >= 인원수가 되면 된다. -> 이를 만족하는 최소 시간 구하면 됨 (이진 탐색으로 극한으로 줄여나가기)

    //시간 범위 : Min time ~ Max time * n
    sort(times.begin(), times.end());
    long long left = times[0];
    long long right = (long long)times[times.size() - 1] * n;

    while(left <= right){
        long long mid = left + (right - left) / 2; //후보시간

        //후보 시간 / 소요시간 몫들의 합 구하기
        long long turnaround = 0;
        for(const auto& t : times)
            turnaround += (mid / t);
        

        if(turnaround < n){ //인원수 이하면 mid를 더 높여서 만족하는 시간을 찾아야 한다
            left = mid + 1;
        }

        else{ //인원수 이상이면 mid를 더 낮춰 현재 mid 보다 작은 시간을 구할 수 있는지 찾기
            answer = mid;
            right = mid - 1;
        }
    }

    return answer;
}