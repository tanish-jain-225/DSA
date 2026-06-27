class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int high = 0;
        int low = 0;
        int result = 0;

        unordered_map<int, int> f;

        for (high = 0; high < n; high++) {
            f[s[high]]++;
            int k = high - low + 1; // Reference

            while (f.size() < k) {
                f[s[low]]--;
                if (f[s[low]] == 0) {
                    f.erase(s[low]);
                }
                low++;
                k = high - low + 1; // Effect on K
            }
            int length = high - low + 1;
            result = max(length, result);
        }
        return result;
    }
};