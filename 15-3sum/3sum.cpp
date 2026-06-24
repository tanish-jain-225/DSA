class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> answer;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            if (nums[i] > 0)
                break;

            int target = nums[i];
            int st = i + 1;
            int end = n - 1;

            while (st < end) {
                if (nums[st] + nums[end] == -target) {
                    answer.push_back({target, nums[st], nums[end]});
                    st++;
                    end--;

                    while (st < end && nums[st] == nums[st - 1])
                        st++;

                    while (st < end && nums[end] == nums[end + 1])
                        end--;

                    continue;
                }
                if (nums[st] + nums[end] > -target) {
                    end--;
                } else {
                    st++;
                }
            }
        }
        return answer;
    }
};