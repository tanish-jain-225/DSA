class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = 1;
        int unique = 1;
        while (high < n) {
            if (nums[high] == nums[high - 1]) {
                high++;
                continue;
            }
            nums[low + 1] = nums[high];
            unique++;
            low++;
            high++;
        }
        return unique;
    }
};