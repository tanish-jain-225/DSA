class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();

        int zero = 0;
        int one = 0;

        int res = 0;

        unordered_map<int, int> f;

        for (int i = 0; i < n; i++) {

            // Count number of 0s and 1s seen so far
            if (nums[i] == 0)
                zero++;
            else
                one++;

            // Difference between number of 0s and 1s
            int diff = zero - one;

            // If difference is 0, then from index 0 to i,
            // number of 0s and 1s are equal.
            if (diff == 0) {
                res = max(res, i + 1);
                continue;
            }

            // First time seeing this difference
            if (f.find(diff) == f.end()) {
                f[diff] = i;
            }
            // Difference seen before
            else {
                int idx = f[diff];

                // Subarray between (idx+1) and i
                // has equal number of 0s and 1s
                int len = i - idx;

                res = max(res, len);
            }
        }

        return res;
    }
};