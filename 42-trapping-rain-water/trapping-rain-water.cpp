class Solution {
public:
    // Function to calculate trapped rain water
    int
    trap(vector<int>& height) // Time Complexity: O(n), Space Complexity: O(n)
    {
        // Edge case: If the height array is empty, return 0
        if (height.empty())
            return 0;

        // Create two vectors to store the maximum height to the left and right
        // of each position
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        int n = height.size();

        // First For Loop: Calculate left max for each position
        leftMax[0] = height[0]; // Initialize the first element
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Second For Loop: Calculate right max for each position
        rightMax[n - 1] = height[n - 1]; // Initialize the last element
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Third For Loop: Calculate total trapped water
        int totalWater = 0; // Initialize total water to 0
        for (int i = 0; i < n; i++) {
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }

        // Return the total trapped water
        return totalWater;
    }
};