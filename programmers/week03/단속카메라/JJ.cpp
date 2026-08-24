/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : ssafy                                   SSSSS   WW   WW  */
/* Algorithm         : 그리디 / 우선순위 큐                    SS      WW   WW  */
/* Time Complexity   : O(NlogN)                                SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : 회의실 예약 문제와 유사                 SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
아이디어 : 두 번째 요소로 오름차순 정렬. (우선순위 큐 이용)
top의 second 값이 그 다음 root로 올 노드들의 first값과 범위가 겹치는지 확인. 겹치면 하나의 카메라로 확인가능함을 뜻함.
-> 겹치는 루트노드가 없을 때까지 pop


예시)
                    -15
|--------------------|     -13
              |-------------|          -5
                         |--------------|        -3
                        -14             |---------|

1. -15를 기준으로 겹치는 구간 카운트 (안겹치면 해당 구간에 카메라 하나 배정 후 pop하면 됨)
2. -15에 설치 시, 두 구간 커버 가능하니 그 다음 구간 -14~-5 구간 계산.
 ....
*/

struct cmp{
    bool operator()(pair<int, int> a, pair<int,int> b){
        if(a.second == b.second)
            return a.first < b.first; //second가 같으면 first 기준으로 내림차순 정렬

        return a.second > b.second; //second가 작은 원소 우선. 오름차순 정렬
    }
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    
    //pq에 원소 삽입
    for(vector<int>& p : routes)
        pq.push({p[0], p[1]});

    while(!pq.empty()){
        //카메라 개수 하나 늘리고 비교 시작
        answer++;
        pair<int, int> temp = pq.top();
        pq.pop();
        
        //겹치는 구간이 있으면 위에서 늘린 카메라로 확인 가능하다는 뜻이므로 pop (겹치는 구간이 없는 노드가 나올 때까지)
        while(!pq.empty() && pq.top().first <= temp.second)
            pq.pop();
    }

    return answer;
}