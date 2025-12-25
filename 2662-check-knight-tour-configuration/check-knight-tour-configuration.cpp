class Solution {
public:
    // Function to check if the knight's move is valid
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal) {
        // Base case: Check for out of bounds and expected value
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal)
            return false;

        // If all moves are done - Solution found
        if (expVal == n * n - 1)
            return true;

        // Explore all 8 possible knight moves
        bool ans1 = isValid(grid, r + 2, c + 1, n, expVal + 1);
        bool ans2 = isValid(grid, r + 1, c + 2, n, expVal + 1);
        bool ans3 = isValid(grid, r - 1, c + 2, n, expVal + 1);
        bool ans4 = isValid(grid, r - 2, c + 1, n, expVal + 1);
        bool ans5 = isValid(grid, r - 2, c - 1, n, expVal + 1);
        bool ans6 = isValid(grid, r - 1, c - 2, n, expVal + 1);
        bool ans7 = isValid(grid, r + 1, c - 2, n, expVal + 1);
        bool ans8 = isValid(grid, r + 2, c - 1, n, expVal + 1);

        // Return true if any of the moves lead to a solution
        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    // Function to check if the knight's move is valid
    bool checkValidGrid(vector<vector<int>>& grid) {
        // Start from the top-left corner of the grid
        int expVal = 0;

        // Call the recursive function to validate the knight's tour
        return isValid(grid, 0, 0, grid.size(), expVal);
    }
};