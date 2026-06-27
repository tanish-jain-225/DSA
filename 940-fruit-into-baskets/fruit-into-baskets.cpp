class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2; // Atmost 2 Condition
        int n = fruits.size();
        int low = 0;
        int high = 0;
        int result = 0;

        unordered_map<int, int> f;

        for (high = 0; high < n; high++) {
            f[fruits[high]]++;

            while (f.size() > k) {
                f[fruits[low]]--;
                if (f[fruits[low]] == 0) {
                    f.erase(fruits[low]);
                }
                low++;
            }
            int length = high - low + 1;
            result = max(length, result);
        }
        return result;
    } // TC: O(n) and SC: O(1)
};