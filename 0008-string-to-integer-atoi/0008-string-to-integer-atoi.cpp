class Solution {
public:
    int fn(string &s, int i, int res, int sign) {
        if (i >= s.size() || s[i] < '0' || s[i] > '9') {
            return res * sign;
        }

        int digit = s[i] - '0';

        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) {
            if (sign == 1) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        }

        return fn(s, i + 1, res * 10 + digit, sign);
    }

    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i >= n) {
            return 0;
        }

        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        return fn(s, i, 0, sign);
    }
};
