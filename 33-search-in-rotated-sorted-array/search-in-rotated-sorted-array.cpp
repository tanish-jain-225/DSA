class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        // ---------------- Part 1 : Find Pivot ----------------

        int low = 0;
        int high = n - 1;
        int idx = 0; // Index of minimum element (pivot)

        while (low <= high) {

            int guess = (low + high) / 2;

            if (nums[guess] > nums[n - 1]) {
                low = guess + 1;
            } else {
                idx = guess;
                high = guess - 1;
            }
        }

        // ---------------- Part 2 : Decide Search Region ----------------

        if (target <= nums[n - 1]) {
            low = idx;
            high = n - 1;
        } else {
            low = 0;
            high = idx - 1;
        }

        // ---------------- Part 3 : Normal Binary Search ----------------

        while (low <= high) {

            int guess = (low + high) / 2;

            if (nums[guess] == target) {
                return guess;
            }

            if (nums[guess] < target) {
                low = guess + 1;
            } else {
                high = guess - 1;
            }
        }

        return -1;
    }
};