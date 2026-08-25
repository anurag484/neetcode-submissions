class Solution {
public:
    int reverse(int x) {
        long long number = 0; // use long long for intermediate calculation
        while (x != 0) {
            int digit = x % 10;
            number = number * 10 + digit;
            
            // check if number goes out of 32-bit int range
            if (number > INT_MAX || number < INT_MIN) {
                return 0;
            }
            x /= 10;
        }
        return (int)number;
    }
};
