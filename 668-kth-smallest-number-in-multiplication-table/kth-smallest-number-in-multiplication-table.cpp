class Solution {
public:
    // Counts how many numbers are <= guess
    int helper(int m, int n, int guess) {

        int count = 0;

        // Check every row
        for (int i = 1; i <= m; i++) {

            // Row i contains:
            // i, 2*i, 3*i, ... n*i

            // Count numbers <= guess in this row
            count += min(guess / i, n);
        }

        return count;
    }

    int findKthNumber(int m, int n, int k) {

        // Search Space
        int low = 1;
        int high = m * n;

        int ans = -1;

        // Binary Search on Answer
        while (low <= high) {

            int guess = low + (high - low) / 2;

            // Count numbers <= guess
            int count = helper(m, n, guess);

            if (count < k) {

                // Need larger values
                low = guess + 1;
            } else {

                // Possible answer
                ans = guess;

                // Try to find a smaller answer
                high = guess - 1;
            }
        }

        return ans;
    }
};