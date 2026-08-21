/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 그리디                                  SS      WW   WW  */
/* Time Complexity   : O(N log N)                              SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end()); // 몸무게 정렬
    int right = people.size()-1; // 제일 무거운 무게 인덱스
    int left = 0; // 제일 가벼운 무게 인덱스
    while(left<=right){ // 제일 무거운 무게가 가벼운 무게보다 오른쪽에 있게
        // 제일 무거운 사람과 제일 가벼운 사람이 같이 탈수있으면 
        // left는 그 다음 가벼운 무게로 옮김
        if(people[left]+people[right]<=limit){
            left++;
        }
        answer++; // 구명보트 한개 사용
        right--; // 제일 무거운 사람은 무조건 구명보트 타게
    }
    return answer;
}
