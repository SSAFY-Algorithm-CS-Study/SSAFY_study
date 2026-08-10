/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 큐, 우선순위큐                          SS      WW   WW  */
/* Time Complexity   : O(N^2)                                  SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include<bits/stdc++.h>

using namespace std;

/*
우선순위 큐와 현재 작업의 우선순위 값 비교.
현재 작업의 우선순위가 우선순위 큐의 top보다 작으면 현 작업보다 더 중요한 작업이 존재함을 의미
-> 현재 작업을 대기큐 맨 뒤에 넣기. 우선순위 제일 큰 작업을 찾을 때까지 반복
-> location에 해당하는 작업이 실행할 수 있게 됐을 때 (우선순위가 제일 높게 되었고 대기큐 제일 앞에 존재하면) 답 출력
*/

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> q; // <우선순위, 인덱스>
    priority_queue<int> pq; //우선순위대로 정렬

    //프로세스스들의 정보 대기큐, 우선순위 큐에 넣기
    for(int i = 0; i < priorities.size(); i++){
      q.push({priorities[i], i});
      pq.push(priorities[i]);
    }
    
    int cnt = 1; //현재 몇 번째 작업인지 (정답 출력용)

    while(!q.empty()){
      int tempJob = q.front().first; //대기큐에서 꺼내온, 현재 작업할 프로그램의 우선순위
      int tempIdx = q.front().second; //대기큐에서 꺼내온, 현재 작업할 프로그램의 인덱스
      int highPriority = pq.top(); //현재 대기큐에 있는 작업들 중 제일 높은 우선순위 값

      if(tempJob == highPriority){ //실행 가능함
        //실행 가능하면서 우리가 찾는 인덱스의 프로세스임. 정답 출력
        if(tempIdx == location){ 
          answer = cnt;
          break;
        }
        //실행만 가능. 실행하고 다음 작업으로
        else{
          cnt++;
          q.pop();
          pq.pop();
        }
      }

      else{ //현재 프로세스 더 높은 우선순위의 프로세스가 존재하므로 실행 불가. 대기큐 맨 뒤로 이동
        q.pop();
        q.push({tempJob, tempIdx});
      }
    }
    return answer;
}