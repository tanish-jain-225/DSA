class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); // Number of bars in the histogram
        vector<int> left(n, 0),
            right(n,
                  0); // Vectors to store the left and right limits for each bar
        stack<int> s; // Stack to keep track of indices of histogram bars

        // Right Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] =
                s.empty()
                    ? n
                    : s.top(); // If no smaller element on right, boundary is n
            s.push(i);
        }

        // Clear the stack to reuse it for left smaller element calculation
        while (!s.empty()) {
            s.pop();
        }

        // Left Smaller Element
        for (int i = 0; i < n; i++) {
            while (s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] =
                s.empty()
                    ? -1
                    : s.top(); // If no smaller element on left, boundary is -1
            s.push(i);
        }

        // Calculate the maximum area using the left and right limits
        int ans = 0; // Variable to store the maximum area found
        for (int i = 0; i < n; i++) {
            int width =
                right[i] - left[i] -
                1; // Calculate the width of the rectangle for the current bar
            int area =
                heights[i] * width; // Calculate the area of the rectangle
            ans = max(
                ans,
                area); // Update the maximum area if the current area is larger
        }
        return ans; // Return the maximum area found
    }
};