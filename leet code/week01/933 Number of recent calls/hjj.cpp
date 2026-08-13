class RecentCounter {
private:
    queue<int> requests;
    int request_cnt;
public:
    RecentCounter() {
        request_cnt = 0;
    }

    int ping(int t) {
        requests.push(t);

        while (requests.front() != t) {
            if ((requests.front() >= t - 3000) && (requests.front() <= t)) {
                requests.push(requests.front());
                requests.pop();
            }
            else {
                requests.pop();
            }
        }
        request_cnt = requests.size();
        return request_cnt;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */