class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();
        vector<int> answer(n);

        int left = 0;
        int right = n - 1;
        int idx = n - 1;

        while (left <= right) {

            if (abs(nums[left]) > abs(nums[right])) {
                answer[idx] = nums[left] * nums[left];
                left++;
            } else {
                answer[idx] = nums[right] * nums[right];
                right--;
            }

            idx--;
        }

        return answer;
    }
};