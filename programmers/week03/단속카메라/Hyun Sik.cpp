/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 그리디                                  SS      WW   WW  */
/* Time Complexity   : O(N log N)                              SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : 프로그래머스 - 단속카메라               SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1]; // 진입, 진출 이므로 진출을 기준으로 정렬
}

int solution(vector<vector<int>> routes) {
    int answer = 0; // 정답 정수

    sort(routes.begin(), routes.end(), compare); // 차량이 진출하는 지점을 기준으로 정렬

    int camera = -30001; // -30000 이상 30000 이하 이므로 일단 더 작은 -30001로 설정
    for (int i = 0; i < routes.size(); i++) // 모든 차량의 수만큼 반복문 실행
    {
        int start = routes[i][0]; // 진입 
        int end = routes[i][1]; // 진출

        if (camera < start) // 진입보다 카메라의 위치가 작다는 것은 카메라가 현재 차량을 단속 못하므로 
        {
            camera = end; // 다음 차량의 범위에 카메라가 포함될 수 있도록  
                          // 가장 나중 값인 진출 값을 새로운 카메라 위치로 설정
            answer++; // 카메라 수가 늘어났으므로 정답 증가
        }
    }

    return answer; // 정답 리턴
}