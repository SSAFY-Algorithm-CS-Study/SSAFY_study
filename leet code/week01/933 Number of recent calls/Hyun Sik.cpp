/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 큐                                      SS      WW   WW  */
/* Time Complexity   : O(1)                                    SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : leet - 933 Number of Recent Calls       SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <queue>
using namespace std;

class RecentCounter
{
private:
    queue<int> q; // 범위에 성립하는 값만 남길 큐 생성

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        q.push(t);                                 // 시간을 큐에 넣기
        while (!q.empty() && q.front() < t - 3000) // 큐가 비어있지 않고 큐의 front 값이 t-3000보다 작다면(범위에 성립하지 않는다면)
        {
            q.pop(); // 범위에 성립하지 않는 값이므로 pop
        }
        return q.size(); // 범위에 성립하는 값만 남아있으므로 큐의 크기 리턴
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */