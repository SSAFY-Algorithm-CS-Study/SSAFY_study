class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int idx = 0;
        for (vector<int> point : points) {
            pq.push({ point[0] * point[0] + point[1] * point[1], idx });
            idx++;
        }

        vector<vector<int>> answer;
        for (int i = 0; i < k; i++) {
            answer.push_back(points[pq.top().second]);
            pq.pop();
        }

        return answer;
    }
};