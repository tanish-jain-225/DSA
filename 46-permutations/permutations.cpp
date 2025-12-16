class Solution {
public:
    // Helper function to generate permutations using backtracking
    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans) {

        // Base case: if idx reaches the end of the array
        if (idx == nums.size()) {
            ans.push_back(nums);
            return; // backtrack
        }

        // Recursive case: swap each element with the current index and recurse
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            getPerms(nums, idx + 1, ans);
            swap(nums[idx], nums[i]); // Re-backtrack
        }
    }

    // Master function to return all permutations
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        // Helper function for backtracking
        getPerms(nums, 0, ans);

        return ans;
    }
};