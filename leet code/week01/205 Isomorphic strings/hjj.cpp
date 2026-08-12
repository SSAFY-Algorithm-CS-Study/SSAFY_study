class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> s_t;
        map<char, char> t_s;
        for (int i = 0; i < s.length(); i++) {
            if (s_t.count(s[i])) {
                if (s_t[s[i]] != t[i]) {
                    return false;
                }
                else {
                    continue;
                }
            }
            if (t_s.count(t[i])) {
                if (t_s[t[i]] != s[i]) {
                    return false;
                }
                else {
                    continue;
                }
            }
            s_t[s[i]] = t[i];
            t_s[t[i]] = s[i];
        }
        return true;
    }
};