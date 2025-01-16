class Solution {
public:
    int maxArea(vector<int>& height) {
        // initialize the maximum water
        // int maxWater = 0;
        int maxWater = 0;

        // initialize the left and right pointers
        int left = 0;
        int right = height.size() - 1;

        // loop until left pointer is less than right pointer
        while (left < right) {
            // calculate the water
            int width = (right - left);
            int data = min(height[left], height[right]);
            int water = width * data;

            // update the maximum water
            maxWater = max(maxWater, water);

            // move the pointer with smaller height
            height[left] < height[right] ? left++ : right--;
        }

        // return the maximum water
        return maxWater;
    }
};