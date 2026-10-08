class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sort(nums.begin(), nums.end()); - Optional
        int n = nums.size();
        int low = 0;
        int high = 0;

        int res = INT_MAX;
        int sum = 0;

        for (int high = 0; high < n; high++) {
            sum += nums[high];

            while (sum >= target) {
                int length = high - low + 1;
                res = min(res, length);

                sum -= nums[low];
                low++;
            }
        }

        if(res == INT_MAX)
        {
            return 0;
        }

        return res;
    }
};