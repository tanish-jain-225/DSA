class Solution {
public:
    int
    trap(vector<int>& height) // Time Complexity: O(n), Space Complexity: O(1)
    {
        // Edge case: If the height array is empty, return 0
        if (height.empty())
            return 0;

        int left = 0;                  // Left pointer
        int right = height.size() - 1; // Right pointer
        int leftMax = 0;               // Maximum height to the left
        int rightMax = 0;              // Maximum height to the right
        int totalWater = 0;            // Total trapped water

        // While left pointer is less than right pointer
        while (left < right) {
            // Update leftMax and rightMax
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            // Calculate trapped water based on the smaller of leftMax and
            // rightMax
            if (leftMax < rightMax) {
                totalWater += (leftMax - height[left]);
                left++; // Move left pointer to the right
            } else {
                totalWater += (rightMax - height[right]);
                right--; // Move right pointer to the left
            }
        }

        // Return the total trapped water
        return totalWater;
    }
};