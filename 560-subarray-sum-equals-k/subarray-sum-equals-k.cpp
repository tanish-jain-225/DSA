class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {

        int n = arr.size();
        int sum = 0;
        int res = 0;

        unordered_map<int, int> f;
        f[0] = 1;

        for (int i = 0; i < n; i++) {

            // Current prefix sum
            sum += arr[i];

            // We need a previous prefix sum = sum - k
            int quest = sum - k;

            // Add its frequency to the answer
            res += f[quest];

            // Store current prefix sum
            f[sum]++;
        }

        return res;
    }
};