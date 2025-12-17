class Solution {
public:
    double p(double x, long long n) {
        if (n == 0) return 1;
        double half = p(x, n / 2);
        if (n % 2 == 0) return half * half;
        return half * half * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return p(x, N);
    }
};
