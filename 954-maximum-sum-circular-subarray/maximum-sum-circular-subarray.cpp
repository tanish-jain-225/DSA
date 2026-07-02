class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int total = nums[0];

        int best = nums[0];
        int maxSum = nums[0];

        int worst = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < n; i++) {

            total += nums[i];

            // Maximum Subarray
            int v1 = best + nums[i];
            int v2 = nums[i];
            best = max(v1, v2);
            maxSum = max(maxSum, best);

            // Minimum Subarray
            int v3 = worst + nums[i];
            int v4 = nums[i];
            worst = min(v3, v4);
            minSum = min(minSum, worst);
        }

        // All numbers are negative
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};