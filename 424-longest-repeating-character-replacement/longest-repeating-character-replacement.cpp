class Solution {
public:
    int find(unordered_map<char, int>& f) {
        int maximum = 0;

        for (auto& it : f)
            maximum = max(maximum, it.second);

        return maximum;
    }

    int characterReplacement(string s, int k) {

        int n = s.size();

        int low = 0;
        int high = 0;

        int result = 0;

        unordered_map<char, int> f;

        for (high = 0; high < n; high++) {
            f[s[high]]++;

            int length = high - low + 1;
            int maxCount = find(f);
            int diff = length - maxCount;

            while (diff > k) {
                f[s[low]]--;
                low++;

                length = high - low + 1;
                maxCount = find(f);
                diff = length - maxCount;
            }

            length = high - low + 1;
            result = max(length, result);
        }
        return result;
    }
};