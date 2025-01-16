class Solution {
public:
    int majorityElement(vector<int>& nums4) {
        int count4 = nums4.size();

        // Sorting the array
        sort(nums4.begin(), nums4.end());

        // freq count
        int freq = 1, ans = nums4[0];
        for (int i = 1; i < count4; i++) {
            if (nums4[i] == nums4[i - 1]) {
                freq++;
            } else {
                freq = 1;
                ans = nums4[i];
            }

            if (freq > count4 / 2) {
                return ans;
            }
        }

        return ans;
    }
};