class Solution {
public:
    vector<vector<int>> mergeInterval(vector<vector<int>>& arr) {
        // No sort required since already sorted order is maintained

        vector<vector<int>> ans;
        int n = arr.size();

        int start1 = arr[0][0];
        int end1 = arr[0][1];

        for (int i = 1; i < n; i++) {
            int start2 = arr[i][0];
            int end2 = arr[i][1];

            if (end1 >= start2) {
                start1 = start1;
                end1 = max(end1, end2);
                continue; // Let loop continue
            }

            ans.push_back({start1, end1}); // Store first instance

            // Update pointers
            start1 = start2;
            end1 = end2;
        }

        // finally push last valid pair
        ans.push_back({start1, end1});

        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> res;

        int n = intervals.size();
        bool inserted = false;

        for (int i = 0; i < n; i++) {

            if (!inserted && intervals[i][0] >= newInterval[0]) {
                res.push_back(newInterval);
                inserted = true;
            }

            res.push_back(intervals[i]);
        }

        if (!inserted)
            res.push_back(newInterval);

        res = mergeInterval(res);

        return res;
    }
};