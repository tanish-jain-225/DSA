// Solution Class
class Solution {
public:
    int orangesRotting(
        vector<vector<int>>& grid) // Function to calculate the minimum time
                                   // required to rot all oranges
    {
        // Multisource BFS approach

        // Initialize all parameters
        queue<pair<pair<int, int>, int>>
            q;       // Queue to store the position and time
        int ans = 0; // Initialize ans to 0

        // Step 1: Push all the initially rotten oranges into the queue -
        // Multiple Points of Source
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) // If the orange is rotten
                {
                    q.push({{i, j}, 0}); // Push the position and time (0 for
                                         // initial rotten oranges)
                }
            }
        }

        // Step 2: Perform BFS to rot the adjacent fresh oranges
        while (!q.empty()) {
            int i, j, time;
            i = q.front().first.first;  // Row index
            j = q.front().first.second; // Column index
            time = q.front().second;    // Time taken to rot the orange
            q.pop(); // Remove the front element from the queue

            ans = max(ans,
                      time); // Update the maximum time taken to rot all oranges

            // Check the four adjacent directions (up, down, left, right)

            // Up
            if (i - 1 >= 0 &&
                grid[i - 1][j] == 1) // If the adjacent orange is fresh
            {
                grid[i - 1][j] = 2; // Mark it as rotten
                q.push(
                    {{i - 1, j},
                     time +
                         1}); // Push the new position and time into the queue
            }
            // Down
            if (i + 1 < grid.size() &&
                grid[i + 1][j] == 1) // If the adjacent orange is fresh
            {
                grid[i + 1][j] = 2; // Mark it as rotten
                q.push(
                    {{i + 1, j},
                     time +
                         1}); // Push the new position and time into the queue
            }
            // Left
            if (j - 1 >= 0 &&
                grid[i][j - 1] == 1) // If the adjacent orange is fresh
            {
                grid[i][j - 1] = 2; // Mark it as rotten
                q.push(
                    {{i, j - 1},
                     time +
                         1}); // Push the new position and time into the queue
            }
            // Right
            if (j + 1 < grid[0].size() &&
                grid[i][j + 1] == 1) // If the adjacent orange is fresh
            {
                grid[i][j + 1] = 2; // Mark it as rotten
                q.push(
                    {{i, j + 1},
                     time +
                         1}); // Push the new position and time into the queue
            }
        }

        // Step 3: Check if there are any fresh oranges left
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) // If there is a fresh orange left
                {
                    return -1; // Return -1 as it's impossible to rot all
                               // oranges
                }
            }
        }

        // If all oranges are rotten, return the maximum time taken
        return ans; // Return the maximum time taken to rot all oranges - this
                    // will be the answer
    }
};