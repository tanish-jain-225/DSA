class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int first = -1;

        // Find first occurrence
        while (low <= high) {

            int guess = (low + high) / 2;

            if (nums[guess] == target) {
                first = guess;
                high = guess - 1;
            } else if (nums[guess] < target) {
                low = guess + 1;
            } else {
                high = guess - 1;
            }
        }

        low = 0;
        high = n - 1;

        int last = -1;

        // Find last occurrence
        while (low <= high) {

            int guess = (low + high) / 2;

            if (nums[guess] == target) {
                last = guess;
                low = guess + 1;
            } else if (nums[guess] < target) {
                low = guess + 1;
            } else {
                high = guess - 1;
            }
        }

        return {first, last};
    }
};