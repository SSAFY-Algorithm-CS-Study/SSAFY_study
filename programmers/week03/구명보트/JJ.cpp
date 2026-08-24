/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : 투포인터/그리디                         SS      WW   WW  */
/* Time Complexity   : O(NlogN)                                SSSSS   WW W WW  */
/* Space Complexity  : O(1)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
아이디어 : 투포인터 처럼 생각하기.
    현재 시점으로 가장 무거운 사람과 가장 가벼운 사람 무게의 합이 limit보다 크다면 어차피 제일 무거운 사람에겐 보트 하나를 할당해야함
    가장 무겁고 가벼운 사람 둘이 limit 이하라면 둘 태우고 다음 사람들을 똑같은 로직으로 보면 됨
*/

int solution(vector<int> people, int limit) {
    int answer = 0;
    //현재 시점 가장 무거운(가벼운) 사람을 추적하기 위해 사전 정렬
    sort(people.begin(), people.end()); 

    int start = 0, end = people.size() - 1;

    //투포인터
    while(start <= end){
        //엣지 케이스. 예외 처리 하지 않으면 한 명의 사람인데 두 사람으로 취급해 보트 수가 안맞게 됨
        //무게 판단 기준이 people[strat] + people[end]이기 때문. 
        if(start == end){
            answer++;
            break;
        }

        //limit보다 크다면 제일 무거운 사람 혼자 보트에 태움
        if(people[start] + people[end] > limit){
            answer++;
            end--;
        }

        //limit 이하면 둘 보내서 태움
        else{
            answer++;
            start++;
            end--;
        }
    }
    
    return answer;
}