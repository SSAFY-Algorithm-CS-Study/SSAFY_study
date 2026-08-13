/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : SSAFY                                   SSSSS   WW   WW  */
/* Algorithm         : 우선순위 큐(min heap)                   SS      WW   WW  */
/* Time Complexity   : O(NlogN)                                SSSSS   WW W WW  */
/* Space Complexity  : O(n)                                       SS   WWW WWW  */
/* Note              :                                         SSSSS    WW WW   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

//우선순위 큐 비교 로직을 정하는 비교 함수
struct cmp{
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
        return get<0>(a) > get<0>(b);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // <거리 , x좌표, y좌표> 저장. cmp함수를 이용해 min heap으로 거리가 가까운 순으로 정렬되게 하였음
        // 데이터 두 개는 pair, 세 개 이상부터는 tuple 사용
        priority_queue<tuple<int, int, int> , 
                        vector<tuple<int, int, int>>,
                        cmp> pq;

        // points 벡터를 순회하며 좌표 및 거리를 구해 pq에 푸쉬
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0]; 
            int y = points[i][1]; 
            int dist = x * x + y * y; // 제곱근을 안씌어도 거리 순위엔 변화가 없으므로 double보다 안전한 int형으로 사용

            pq.push({dist, x, y}); // 원점과 가까운 점들 순으로 내부 정렬될 것임
        }
        
        vector<vector<int>> result(k, vector<int>(2));

        for(int i = 0; i < k; i++){
            auto temp = pq.top();
            pq.pop();
            int x = get<1>(temp); // 원점으로부터 가장 가까운 점의 x 좌표 추출
            int y = get<2>(temp); // 원점으로부터 가장 가까운 점의 y 좌표 추출
            result[i][0] = x;
            result[i][1] = y;
        }

        return result;
    }
};

/*
int main(void)
{
    Solution sol;
    vector<vector<int>> points1 = {{1,3}, {-2,2}}, points2 = {{3,3}, {5,-1}, {-2,4}};

    vector<vector<int>> result1 = sol.kClosest(points1, 1),
                        result2 = sol.kClosest(points2, 2);

    for(int i = 0; i < result1.size(); i++){
        for(int j = 0; j < result1[i].size(); j++){
            cout << result1[i][j] << ' ';
        }   
        cout << '\n';
    }

    cout << "\n\n";
    
    for(int i = 0; i < result2.size(); i++){
        for(int j = 0; j < result2[i].size(); j++){
            cout << result2[i][j] << ' ';
        }   
        cout << '\n';
    }
}*/