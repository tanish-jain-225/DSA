class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a, b; // a is repeating, b is missing

        int expSum = 0, actualSum = 0; // For missing number calculation

        // Find repeating
        for (int i = 0; i < n; i++) {
            // Check rows
            for (int j = 0; j < n; j++) {
                actualSum += grid[i][j];

                // Check if already exists
                if (s.find(grid[i][j]) != s.end()) {
                    // Found repeating
                    a = grid[i][j];
                    ans.push_back(a);
                } else {
                    // Insert into set - not found
                    s.insert(grid[i][j]);
                }
            }
        }

        // Calculate expected sum of first n*n natural numbers - Missing number
        // calculation
        expSum = (n * n * (n * n + 1)) / 2;

        b = expSum - actualSum + a; // missing = expected - (actual - repeating)
        ans.push_back(b);

        return ans;
    }
};