class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket_stack;

        if (s.length() % 2 == 0) {
            for (char bracket : s) {
                if (!bracket_stack.empty()) {
                    if ((bracket_stack.top() == '(' && bracket == ')') ||
                        (bracket_stack.top() == '{' && bracket == '}') ||
                        (bracket_stack.top() == '[' && bracket == ']')) {
                        bracket_stack.pop();
                        continue;
                    }
                }
                bracket_stack.push(bracket);
            }
            if (bracket_stack.empty()) {
                return true;
            }
        }
        return false;
    }
};