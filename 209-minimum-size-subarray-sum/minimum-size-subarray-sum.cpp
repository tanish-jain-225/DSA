class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        int result = INT_MAX;
        int sum = 0;

        for (high = 0; high < n; high++) {
            // Add info
            sum += nums[high];

            // Information is Correct
            while (sum >= target) {
                int length = high - low + 1;
                result = min(length, result);
                sum -= nums[low];
                low++;
            }
            // Info is wrong thus did nothing already handled
        }
        if (result == INT_MAX) // In case sum never gets greater than target
        {
            return 0;
        }
        return result;
    }
};