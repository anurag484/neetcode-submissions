class Solution {
public:
    double myPow(double x, int n) {
        // Convert to long long to prevent overflow for INT_MIN
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return power(x, N);
    }

private:
    double power(double x, long long n) {
        // Base case
        if (n == 0) return 1.0;

        // Divide and conquer
        double half = power(x, n / 2);

        if (n % 2 == 0) {
            return half * half;      // Even exponent
        } else {
            return half * half * x;  // Odd exponent
        }
    }
};
