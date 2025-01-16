class Solution {
public:
    double myPow(double x, int n) {
        // Handle edge cases
        if (x == 0) return 0;  // Base case: 0^n = 0 for n > 0
        if (n == 0) return 1;  // Base case: x^0 = 1
        
        // Handle negative power
        long long exp = n;  // Use long long to avoid overflow
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        
        // Efficient power calculation using binary exponentiation
        double res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {  // If the current power is odd
                res *= x;
            }
            x *= x;  // Square the base
            exp /= 2;  // Reduce the power by half
        }
        
        return res;
    }
};
