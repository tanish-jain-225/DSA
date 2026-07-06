class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;

        // Step 1: Calculate total sum of the array
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int left = 0; // Sum of elements to the left of current index

        // Step 2: Traverse each index and check if it is a pivot
        for (int i = 0; i < n; i++) {

            // Right sum = Total sum - Left sum - Current element
            int right = sum - left - nums[i];

            // If left and right sums are equal, current index is the pivot
            if (left == right) {
                return i;
            }

            // Include current element in left sum for the next iteration
            left += nums[i];
        }

        // No pivot index found
        return -1;
    }
};