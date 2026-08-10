/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 덱, 시뮬레이션                          SS      WW   WW  */
/* Time Complexity   : O(NlogN)                                SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;
/*
0 1 2 3 4  5  6
2 3 5 7 11 13 17

0 1 2 3 4 5 6
 2 3 4 5 6 1
  4 5 6 1 3
   6 1 3 5
    3 5 1
     1 5
      5

인덱스가 아래 순으로 공개된다.

0 -> 2 -> 4 -> 6 -> 3 -> 1 -> 5
2    3    5    7    11   13   17

즉, 정렬된 deck 벡터의 각 값들을 위 인덱스에 대응시키면 정답 배열이 완성된다.
*/
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int size = deck.size();

        //덱에 0~size-1까지 값 추가
        deque<int> dq;
        for(int i = 0; i < size; i++)
            dq.push_back(i);
        
        //문제대로 덱 맨 앞 공개, 뒤로 보내기를 반복하면서 인덱스 공개 순서를 추출하면서 answer에 답을 넣어준다
        sort(deck.begin(), deck.end());
        vector<int> answer(size);

        for(int i = 0; i < size; i++){
            //덱 맨 위 추출
            int idx = dq.front();
            dq.pop_front();
            answer[idx] = deck[i];
            /*
            예제 상 idx는 0 2 4 6 3 1 5 가 됨.
            deck[i]는 2, 3, 5, 7, 11, 13, 17
            즉, answer[0] = 2
                answer[2] = 3
                answer[4] = 5
                ...
                answer[1] = 13
                answer[5] = 17
            */

            //추출 후 제일 위에 있는 카드 뒤로 보내기
            int temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }

        return answer;
    }
};

/*
int main(void)
{
    Solution sol;
    vector<int> deck1 = {17,13,11,2,3,5,7} , deck2 = {1, 1000};

    vector<int> result1 = sol.deckRevealedIncreasing(deck1), result2 = sol.deckRevealedIncreasing(deck2);

    for(auto n : result1)
        cout << n << ' ';
    cout << '\n';
    for(auto n : result2)
        cout << n << ' ';
}*/