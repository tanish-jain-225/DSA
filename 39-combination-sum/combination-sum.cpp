class Solution {
public:
    // Function Check Set
    set<vector<int>> s;

    // Helper Function to get all combinations
    void getAllCombinations(vector<int>& arr, int idx, int target,
                            vector<vector<int>>& ans, vector<int>& combin) {

        // Base Case
        if (idx == arr.size() || target < 0) {
            return;
        }

        // Valid Combination - Found a combination
        if (target == 0) {
            // Check in Set
            if (s.find(combin) == s.end()) {
                ans.push_back(combin); // Push into Answer
                s.insert(combin);      // Insert into Set
            }
            return;
        }

        // Inclusion Case

        combin.push_back(arr[idx]); // Pick

        // Single
        getAllCombinations(arr, idx, target - arr[idx], ans, combin);

        // Multiple
        getAllCombinations(arr, idx + 1, target - arr[idx], ans, combin);

        // Exclusion Case

        combin.pop_back(); // Backtrack

        // Not Pick
        getAllCombinations(arr, idx + 1, target, ans, combin);
    }

    // Main Function to return all combinations
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {

        // Resultant Vector
        vector<vector<int>> ans;
        vector<int> combination;

        // Call Helper Function
        getAllCombinations(arr, 0, target, ans, combination);

        // Return Resultant Vector
        return ans;
    }
};