class Solution {
public:
    bool isValid(string s) {
        stack<char> k;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                k.push(c);
            } else {
                if (k.empty()) return false;
                char ch = k.top();
                k.pop();
                if ((c == ')' && ch != '(') || 
                    (c == '}' && ch != '{') || 
                    (c == ']' && ch != '[')) {
                    return false;
                }
            }
        }
        return k.empty();
    }
};
