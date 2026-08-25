class Solution {
public:
    double myPow(double x, int n) {
        // Handle negative exponent
        long long N = n; // Use long long to prevent overflow for INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) { // If N is odd, multiply by x
                result *= x;
            }
            x *= x;  // Square x
            N /= 2;  // Divide exponent by 2
        }
        return result;
    }
};
