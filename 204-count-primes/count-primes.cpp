class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(
            n + 1, true); // Create a boolean array to mark prime numbers
        int count = 0;    // Initialize count of prime numbers

        for (int i = 2; i < n; i++) {
            if (isPrime[i]) { // If i is prime
                count++;      // Increment count of prime numbers
                // Mark all multiples of i as non-prime
                for (int j = i * 2; j < n; j += i) {
                    isPrime[j] = false; // Mark multiples of i as non-prime
                }
            }
        }
        return count; // Return the count of prime numbers
    }
};