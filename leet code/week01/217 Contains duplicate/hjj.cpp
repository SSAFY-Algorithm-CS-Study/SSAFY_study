class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> check_twice;
        for (int n : nums) {
            if (!check_twice.insert(n).second) {
                return true;
            }
        }
        return false;
    }
};