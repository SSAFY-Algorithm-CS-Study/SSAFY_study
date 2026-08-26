/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 그리디                                  SS      WW   WW  */
/* Time Complexity   : O(N log N)                              SSSSS   WW W WW  */
/* Space Complexity  : O(log N)                                   SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), // 나간 지점을 기준으로 sort
     [](vector<int>& a, vector<int>& b) {
         return a[1] < b[1];
     });
    int now = 0; // 카메라를 제일 먼저 나가는 지점에 설치함
    for(int i=1;i<routes.size();i++){
        // 제일 먼저 나가는 지점보다 i번째 차량이 진입한 지점이 더 나중이면
        if(routes[now][1] <routes[i][0]){ 
            answer++; // 카메라 한개 더 추가
            now = i; // i번째 차량이 나가는 지점에 카메라 설치
        }
    }
    return answer;
}