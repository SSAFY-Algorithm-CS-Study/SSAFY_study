class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> dq;
        int n = deck.size();
        for (int idx = 0; idx < n; idx++) {
            dq.push_back(idx);
        }

        // save the order of indexes
        queue<int> indexes;
        while (!dq.empty()) {
            indexes.push(dq.front());
            dq.pop_front();
            if (!dq.empty()) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }

        // sort deck
        sort(deck.begin(), deck.end());

        // save output
        vector<int> output(n, 0);
        for (int i = 0; i < n; i++) {
            output[indexes.front()] = deck[i];
            indexes.pop();
        }

        return output;
    }
};