class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if (k <= 1)
            return 0;

        int n = nums.size();
        int low = 0;
        int high = 0;
        int product = 1;
        int count = 0;

        for (high = 0; high < n; high++) {

            // Add current element
            product *= nums[high];

            // Shrink window until product becomes valid
            while (product >= k) {
                product /= nums[low];
                low++;
            }

            // Count all valid subarrays ending at high
            count += (high - low + 1);
        }

        return count;
    }
};