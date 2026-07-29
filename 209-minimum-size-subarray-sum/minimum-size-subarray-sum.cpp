class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = 0;
        int sum = 0;
        int res = INT_MAX;

        for (high = 0; high < n; high++) {
            // Pehle Sahi tak badhao : High++
            sum += nums[high];

            while (sum >= target) // Jabtak Sahi store and ghatao : low++
            {
                // Store
                int length = high - low + 1;
                res = min(res, length);

                // Ghatao
                sum -= nums[low];
                low++;
            }
            // Yaha tak pahuch gaye balle balle minimum window hai tumhare pass
        }

        // Agar kuch nahi bane toh return 0
        if (res == INT_MAX) {
            return 0;
        }

        // Bana hai toh answer return
        return res;
    }
};