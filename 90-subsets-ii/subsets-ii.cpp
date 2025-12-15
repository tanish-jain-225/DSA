class Solution {
public:
    void getAllSubsets(vector<int>& arr, vector<int>& ans, int start,
                       vector<vector<int>>& allSubsets) {
        allSubsets.push_back(ans);
        for (int i = start; i < arr.size(); i++) {
            if (i > start && arr[i] == arr[i - 1])
                continue;
            ans.push_back(arr[i]);
            getAllSubsets(arr, ans, i + 1, allSubsets);
            ans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort the input to handle duplicates
        sort(nums.begin(), nums.end());

        // Helper function for backtracking
        vector<vector<int>> allSubsets;

        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};