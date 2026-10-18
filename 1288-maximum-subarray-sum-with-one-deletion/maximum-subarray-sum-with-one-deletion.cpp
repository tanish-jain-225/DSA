class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // Loop Helpers
        int n = arr.size();
        int i;

        // Starting Power States
        int power = 0;
        int noPower = arr[0];

        // Inital result
        int res = arr[0];

        // Check all in loop
        for (i = 1; i < n; i++) {
            // No Power
            int v1 = arr[i];
            int v2 = noPower + arr[i];

            // Power used
            int v3 = power + arr[i];
            int v4 = noPower;

            // Store best
            res = max(res, max(max(v1, v2), max(v3, v4)));

            // Update
            noPower = max(v1, v2);
            power = max(v3, v4);
        }

        // return best case subarray option by kadane
        return res;
    }
};