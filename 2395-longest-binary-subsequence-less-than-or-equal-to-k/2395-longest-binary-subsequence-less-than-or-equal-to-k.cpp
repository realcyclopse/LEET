class Solution {
public:
    int longestSubsequence(string s, int k) {
    int cur = 0, pow = 1, i = s.size() - 1;
    for (; i >= 0 && cur + pow <= k; --i) {
        cur += (s[i] - '0') * pow;
        pow <<= 1;
    }
    return i < 0 ? s.size() : count(begin(s), begin(s) + i + 1, '0') + s.size() - i - 1;
}
};