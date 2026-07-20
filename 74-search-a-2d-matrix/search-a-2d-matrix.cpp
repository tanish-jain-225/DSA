class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Binary Search on the entire matrix
        int low = 0;
        int high = rows * cols - 1;

        while (low <= high) {

            // Middle index in the virtual 1D array
            int guess = low + (high - low) / 2;

            // Convert 1D index to 2D position
            int r = guess / cols;
            int c = guess % cols;

            // Target found
            if (matrix[r][c] == target) {
                return true;
            }

            // Search in the right half
            if (matrix[r][c] < target) {
                low = guess + 1;
            }
            // Search in the left half
            else {
                high = guess - 1;
            }
        }

        // Target not found
        return false;
    }
};