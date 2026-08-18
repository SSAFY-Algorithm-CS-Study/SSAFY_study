/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : Park Yeonseo                            SSSSS   WW   WW  */
/* Algorithm         : Deque                                   SS      WW   WW  */
/* Time Complexity   : O(N log N)                              SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end()); // deck sort
        deque<int> dq; // deck 길이에 따른 정답 인덱스 정렬
        vector<int> index; // deck 길이에 따른 정답 인덱스 저장용
        for(int i = 0;i<deck.size();i++){
            dq.push_back(i); //덱에 인덱스를 넣음
        }
        while(!dq.empty()){
            index.push_back(dq.front()); //맨앞 원소 index에 push
            dq.pop_front(); // 맨 앞 원소 pop
            if(!dq.empty()){ // dq가 안비었으면, 맨앞에원소를 맨 뒤로 이동
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        vector<int> answer(deck.size()); // 답이 들어갈 vector
        vector<int> answer(deck.size()); // 답이 들어갈 vector
        for(int i = 0;i<deck.size();i++){
            answer[index[i]] = deck[i]; // 인덱스 순서대로 answer에 저장
            answer[index[i]] = deck[i]; // 인덱스 순서대로 answer에 저장
        }
        return answer;
    }
};
