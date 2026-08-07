/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : Park Yeonseo                            SSSSS   WW   WW  */
/* Algorithm         : Simulation, Greedy                      SS      WW   WW  */
/* Time Complexity   : O(N^2)                                  SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1, head=0, maxIndex;
    vector<int> index;
    for(int i = 0;i< priorities.size();i++){ // priorities의 index만 저장하는 vector
        index.push_back(i);
    }
    while(index[max_element(priorities.begin(), priorities.end()) - priorities.begin()] != location){ // priorities의 max index가 location과 다르면 반복
        maxIndex = max_element(priorities.begin(), priorities.end()) - priorities.begin(); // priorities의 max index
        answer++; // 몇번 반복했는지
        for(int i = head;i<maxIndex;i++){ // head 부터 maxindex까지 push하고 원래 있던 값은 0으로, index 도 똑같이 
            priorities.push_back(priorities[i]);
            priorities[i] = 0;
            index.push_back(index[i]);
        }
        priorities[maxIndex] = 0; // maxIndex도 0으로 바꿔준다.
        head = maxIndex+1; // head를 maxIndex+1로 바꿔 불필요한 연산 줄임
    }
    return answer;
}