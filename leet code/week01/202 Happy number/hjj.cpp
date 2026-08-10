class Solution {
public:

    int oneProcess(int num) {
        int sum = 0;
        for (char c : to_string(num)) {
            sum += (int(c) - int('0')) * (int(c) - int('0'));
        }
        return sum;
    }

    bool isHappy(int n) {
        set<int> num_set;
        while (true) {
            n = oneProcess(n);
            if (n == 1) {
                return true;
            }
            else if (!num_set.insert(n).second) {
                return false;
            }
        }
    }
};