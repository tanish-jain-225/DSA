class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int result = 0;

        unordered_map<int, int> f;

        for (int high = 0; high < n; high++) {
            f[nums[high]]++;

            while (f[0] > k) {
                f[nums[low]]--;
                low++;
            }

            int length = high - low + 1;
            result = max(result, length);
        }

        return result;
        
    } // TC: O(n) and SC: O(1)
};