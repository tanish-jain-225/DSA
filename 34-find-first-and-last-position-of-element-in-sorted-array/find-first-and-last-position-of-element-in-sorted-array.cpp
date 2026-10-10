class Solution {
public:
    int first(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int res = -1;

        while (low <= high) {
            int guess = (low + high) / 2;

            if (nums[guess] == target) {
                res = guess;
                high = guess - 1;
            } else if (nums[guess] < target) {
                low = guess + 1;
            } else {
                high = guess - 1;
            }
        }
        return res;
    }

    int last(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int res = -1;

        while (low <= high) {
            int guess = (low + high) / 2;

            if (nums[guess] == target) {
                res = guess;
                low = guess + 1;
            } else if (nums[guess] < target) {
                low = guess + 1;
            } else {
                high = guess - 1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer;
        int firstOcc = first(nums, target);
        int lastOcc = last(nums, target);

        answer.push_back(firstOcc);
        answer.push_back(lastOcc);

        return answer;
    }
};