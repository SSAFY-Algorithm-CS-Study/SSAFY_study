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
        sort(deck.begin(), deck.end());
        deque<int> dq;
        vector<int> index;
        for(int i = 0;i<deck.size();i++){
            dq.push_back(i);
        }
        while(!dq.empty()){
            index.push_back(dq.front());
            dq.pop_front();
            if(!dq.empty()){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        vector<int> answer(deck.size());
        for(int i = 0;i<deck.size();i++){
            answer[index[i]] = deck[i];
        }
        return answer;
    }
};