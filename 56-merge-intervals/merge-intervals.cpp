class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort given interval
        sort(intervals.begin(), intervals.end());

        // Result Vector
        vector<vector<int>> res;

        // variables
        int n = intervals.size();
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        // Loop to check all ranges starting from index 1. Since 0 is handled by
        // (s1, e1)
        for (int i = 1; i < n; i++) {
            // Create current range
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            // Check if Overlap
            if (end1 >= start2) // Yes - Merge required
            {
                start1 = start1;
                end1 = max(end1, end2);
                continue; // Merge till conditions break
            }

            // After condtion breaks store this instance
            res.push_back({start1, end1});

            // Since condition break replace them with current pointers
            start1 = start2;
            end1 = end2;
        }
        // After loop finshes all, remaining start and end is also a valid pair
        // and must be push to result
        res.push_back({start1, end1});

        // Return answer
        return res;
    }
};