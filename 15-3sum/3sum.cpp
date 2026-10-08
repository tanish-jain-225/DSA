class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 1; i++) {
            // check for i
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // skip and next loop
            }

            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    res.push_back({nums[left], nums[right], nums[i]});
                    left++;
                    right--;

                    // check left valid
                    while (left < n && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // check right valid
                    while (right > 0 && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};