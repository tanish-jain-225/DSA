class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();      // size of array
        int bestEnding = nums[0]; // consider first element to be best
        int ans = nums[0];        // consider answer to be first element

        for (int i = 1; i < n; i++) {
            int v1 = bestEnding + nums[i]; // case 1 : best + current
            int v2 = nums[i];              // case 2 : current only

            bestEnding = max(v1, v2); // the optimisation which is asked here
                                      // max of both versions

            ans = max(ans, bestEnding); // update answer till loop completes
        }

        return ans; // return best optimised answer
    }
};