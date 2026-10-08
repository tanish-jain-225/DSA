class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(); 
        int resSum = 0;
        int maxDiff = INT_MAX;

        sort(nums.begin(), nums.end()); // Sorting is necessary

        for (int i = 0; i < n - 1; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];

                int diff = abs(sum - target); 
                if (maxDiff > diff) {
                    maxDiff = diff;
                    resSum = sum;
                }

                if (sum == target) {
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return resSum;
    }
};