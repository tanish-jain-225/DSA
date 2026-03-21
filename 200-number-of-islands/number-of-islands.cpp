// Solution Class
class Solution {
public:
    // Helper function to perform Depth-First Search (DFS) to mark all connected
    // land cells as visited
    void dfs(int i, int j, vector<vector<bool>>& visited,
             vector<vector<char>>& grid, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] ||
            grid[i][j] == '0') {
            return;
        } // Base case: if out of bounds, already visited, or water, return

        visited[i][j] = true; // Mark the current cell as visited

        dfs(i - 1, j, visited, grid, n, m); // up
        dfs(i + 1, j, visited, grid, n, m); // down
        dfs(i, j + 1, visited, grid, n, m); // right
        dfs(i, j - 1, visited, grid, n, m); // left
    }

    // Main function to count the number of islands in the grid
    int numIslands(vector<vector<char>>& grid) {
        // Initialize all variables and data structures needed for the algorithm
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(
            n, vector<bool>(m, false)); // Create a visited matrix to keep track
                                        // of visited cells

        // Iterate through each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, visited, grid, n,
                        m);    // Start DFS to mark all connected land cells
                    islands++; // Increment the island count after a complete
                               // DFS traversal
                }
            }
        }

        // Return the total number of islands found
        return islands;
    }
};