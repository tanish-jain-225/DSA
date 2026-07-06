class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = 0;
        int sum = 0;

        unordered_map<int, int> f;
        f[0] = 1;

        for (int i = 0; i < n; i++) {

            // Compute prefix sum
            sum += nums[i];

            // Compute remainder
            int rem = sum % k;

            // Handle negative remainder
            if (rem < 0) {
                rem += k;
            }

            // Count previous prefix sums with the same remainder
            ans += f[rem];

            // Store current remainder
            f[rem]++;
        }

        return ans;
    }
};