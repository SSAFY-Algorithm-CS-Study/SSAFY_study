/********************************************************************************/
/* File Name         : YS.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 우선순위 큐                             SS      WW   WW  */
/* Time Complexity   : O(N log N)                              SSSSS   WW W WW  */
/* Space Complexity  : O(N)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/
#include <queue>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,
               vector<vector<int>>,
               greater<vector<int>>> pq; // 우선순위 바뀐 pq
        vector<vector<int>> v;
        for(int i =0;i<points.size();i++){
            // [거리, x, y]값 푸시
            pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],points[i][0], points[i][1] });
        }
        for(int i=0;i<k;i++){ // k개 만큼만 제일 작은거 v에 푸시하고 pq에서 pop하기
            v.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }
        
        return v;
    }
};