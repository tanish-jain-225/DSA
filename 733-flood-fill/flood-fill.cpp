class Solution {
public:
    // Helper function to perform depth-first search
    void dfs(vector<vector<int>>& image, int i, int j, int newColor,
             int oldColor) {
        // Base case: Check if the current pixel is out of bounds or does not
        // match the old color or is already colored with the new color
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() ||
            image[i][j] != oldColor || image[i][j] == newColor) {
            return;
        }

        // Update the color of the current pixel
        image[i][j] = newColor;

        // Recursively call dfs for the neighboring pixels
        dfs(image, i - 1, j, newColor, oldColor); // Up
        dfs(image, i + 1, j, newColor, oldColor); // Down
        dfs(image, i, j - 1, newColor, oldColor); // Left
        dfs(image, i, j + 1, newColor, oldColor); // Right
    }

    // Main function to perform flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Get the original color of the starting pixel
        int oldColor = image[sr][sc];

        // If the old color is different from the new color, perform the flood
        // fill
        if (oldColor != newColor) {
            // Call the helper function to perform depth-first search
            dfs(image, sr, sc, newColor, oldColor);
        }
        // Return the modified image
        return image;
    }
};