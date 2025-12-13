class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();

        // Sort the array to facilitate the two-pointer technique and duplicate
        // handling
        sort(nums.begin(), nums.end());

        // Iterate through the array with two nested loops for the first two
        // numbers
        for (int i = 0; i < n; i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Two-pointer approach for the remaining two numbers
                int start = j + 1;
                int end = n - 1;
                while (start < end) {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[start] + nums[end];
                    if (sum == target) {
                        result.push_back(
                            {nums[i], nums[j], nums[start], nums[end]});

                        // Skip duplicates for the third number
                        while (start < end && nums[start] == nums[start + 1])
                            start++;

                        // Skip duplicates for the fourth number
                        while (start < end && nums[end] == nums[end - 1])
                            end--;

                        start++; // Move to the next different number
                        end--;   // Move to the previous different number
                    } else if (sum < target) {
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }

        return result;
    }
};