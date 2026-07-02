class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();      // Size/Range
        int bestEnding = nums[0]; // Case Selector
        int ans = nums[0];        // Initial Assumed Answer

        for (int i = 1; i < n; i++) // From 1 to n
        {
            int v1 = bestEnding + nums[i]; // Case 1
            int v2 = nums[i];              // Case 2
            bestEnding = max(v1, v2);   // Selected Best Case of Current Index
            ans = max(bestEnding, ans); // Max of best case and previous answer
        }

        return ans; // Final Answer
    }
};