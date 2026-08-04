/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 큐                                      SS      WW   WW  */
/* Time Complexity   : O(1)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : leet - 933 Number of Recent Calls       SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end()); // 오름차순으로 정렬
        deque<int> result;              // 결과를 저장할 덱, 덱을 사용하는 이유는 앞과 뒤에서 삽입/삭제가 가능하기 때문

        while (!deck.empty()) // deck가 비어있지 않다면 반복문 실행
        {
            int pastLast = deck.back(); // deck의 마지막 값을 pastLast에 저장
            deck.pop_back();            // deck의 마지막 값 제거

            if (!result.empty()) // result가 비어있지 않다면(처음 제외)
            {
                result.push_front(result.back()); // result의 마지막 값을 result의 앞에 삽입
                result.pop_back();                // result의 마지막 값 제거
            }
            result.push_front(pastLast); // pastLast 값을 result의 앞에 삽입
        }
        return vector<int>(result.begin(), result.end()); // 덱을 벡터로 변환하여 반환
    }
};