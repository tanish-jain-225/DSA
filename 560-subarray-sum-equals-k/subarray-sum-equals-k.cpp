class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0; // Initialize count of subarrays

        // Create a hash map to store the frequency of prefix sums
        vector<int> prefix_sum(n, 0);

        // Initialize prefix sums
        prefix_sum[0] = arr[0];

        // Compute the prefix sum array
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + arr[i];
        }

        // Iterate through all possible subarrays using prefix sums

        unordered_map<int, int> m; // Hash map to store frequency of prefix sums

        m[0] = 1; // Initialize map with 0 sum frequency for subarrays starting
                  // from index 0

        // Traverse the prefix sum array
        for (int j = 0; j < n; j++) {
            // Check if there is a prefix sum that, when subtracted from current
            // prefix sum, gives k
            int val =
                prefix_sum[j] -
                k; // We need to find if (prefix_sum[j] - k) exists in the map

            // If such a prefix sum exists, add its frequency to the count
            if (m.find(val) != m.end()) {
                count += m[val]; // Increment count by the frequency of
                                 // (prefix_sum[j] - k)
            }

            // Increment the frequency of the current prefix sum
            m[prefix_sum[j]]++;
        }

        // Return the total count of subarrays with sum equal to k
        return count;
    }
};