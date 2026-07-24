class Solution {
public:
    int longestPalindrome(string s) {

        int n = s.size();
        unordered_map<char, int> f;

        // Store frequencies
        for (int i = 0; i < n; i++) {
            f[s[i]]++;
        }

        int evenSum = 0;
        int odd = 0;

        for (int i = 0; i < n; i++) {

            // Skip if this character is already processed
            if (f.find(s[i]) == f.end()) {
                continue;
            }

            int freq = f[s[i]];

            if (freq % 2 == 0) {
                evenSum += freq;
            } else {
                evenSum +=
                    freq -
                    1;   // Make that odd freq to even and add that to evenSum
                odd = 1; // Use Any One final odd of freq one
            }

            // Remove so it is not processed again
            f.erase(s[i]);
        }

        return evenSum + odd;
    }
};