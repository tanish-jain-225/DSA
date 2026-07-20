class Solution {
public:
    // Counts how many elements are <= guess
    int helper(vector<vector<int>>& matrix, int n, int m, int guess) {

        int row = n - 1; // Start from bottom-left
        int col = 0;

        int count = 0;

        while (row >= 0 && col < m) {

            // Current element is <= guess
            if (matrix[row][col] <= guess) {

                // All elements above in this column are also <= guess
                count += row + 1;

                // Move to next column
                col++;
            } else {

                // Current element is too large
                // Move one row up
                row--;
            }
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();
        int m = matrix[0].size();

        // Search Space
        int low = matrix[0][0];
        int high = matrix[n - 1][m - 1];

        int ans = -1;

        // Binary Search on Answer
        while (low <= high) {

            int guess = low + (high - low) / 2;

            // Count elements <= guess
            int count = helper(matrix, n, m, guess);

            if (count < k) {

                // Need larger values
                low = guess + 1;
            } else {

                // Possible answer
                ans = guess;

                // Try finding a smaller valid answer
                high = guess - 1;
            }
        }

        return ans;
    }
};