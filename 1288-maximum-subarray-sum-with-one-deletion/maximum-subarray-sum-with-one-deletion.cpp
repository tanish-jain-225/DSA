class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // Size of array
        int n = arr.size();

        // Initial values
        int noDelete = arr[0];
        int oneDelete = arr[0];
        int result = arr[0];

        for (int i = 1; i < n; i++) {

            // Save previous states
            int prevNoDelete = noDelete;
            int prevOneDelete = oneDelete;

            // Candidates

            // noDelete Conditions
            int v1 = prevNoDelete + arr[i];   // Extend without deletion
            int v2 = arr[i];                  // Start new subarray

            // oneDelete Conditions
            int v3 = prevOneDelete + arr[i];  // Already deleted, extend
            int v4 = prevNoDelete;            // Delete current element

            // max out values
            noDelete = max(v1, v2);
            oneDelete = max(v3, v4);

            // best possible outcome
            result = max(result, max(noDelete, oneDelete));
        }

        // answer 
        return result;
    }
};