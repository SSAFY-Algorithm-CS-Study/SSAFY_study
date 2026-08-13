/********************************************************************************/
/* File Name         : Hyun Sik.cpp                                             */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 우선순위 큐                             SS      WW   WW  */
/* Time Complexity   : O(N log N)                              SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              : leet : 973 K Closest Points to Origin   SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using p = pair<int, pair<int, int>>; // 길이, <좌표y, 좌표x>
        priority_queue<p, vector<p>, greater<p>> pq; // 우선순위 큐를 활용해서 길이 짧은 순으로 우선 정렬되어 확인하고 꺼낼 수 있도록 함(가까운 순이므로)

        for (int i = 0; i < points.size(); i++) // 벡터의 크기만큼 반복문 실행(좌표 개수만큼)
        {
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1]; // 길이(다른 한 좌표가 0, 0 이므로 바로 제곱)
            pq.push({ distance, { points[i][0] , points[i][1] } }); // 만든 우선순위 큐에 대입, 넣으면 바로 길이 순으로 정렬
        }

        vector<vector<int>> answer(k, vector<int>(2)); // 정답 벡터
        for (int i = 0; i < k; i++) // k만큼 리턴해야 하므로 k만큼 반복문 실행
        {
            answer[i][0] = pq.top().second.first; // 정답 벡터의 0번째 인덱스에는 우선순위 큐의 좌표y값
            answer[i][1] = pq.top().second.second; // 정답 벡터의 1번째 인덱스에는 우선순위 큐의 좌표x값
            pq.pop(); // 꺼내야 다음걸 top 으로 확인 가능
        }

        return answer; // 정답 벡터 리턴
    }
};