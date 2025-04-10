class Solution {
public:
    bool isFreqSame(int freq1[],
                    int freq2[]) // TC=O(26) = O(1) - Space Complexity: O(1)
    {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i])
                return false; // Frequencies are not the same
        }
        return true; // Frequencies are the same
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            int idx = s1[i] - 'a'; // Convert char to index (0-25) a => 0, b =>
                                   // 1, ..., z => 25
            freq[idx]++;
        }

        int windowSize = s1.length();

        for (int i = 0; i < s2.length(); i++) {
            int windowIdx = 0, idx = i;
            int windowFreq[26] = {0}; // Frequency array for the current window

            while (windowIdx < windowSize && idx < s2.length()) {
                windowFreq[s2[idx] - 'a']++; // Increment frequency of the
                                             // current character in the window
                idx++;
                windowIdx++;
            }

            if (isFreqSame(freq, windowFreq)) {
                // Check if the frequency arrays are the same
                return true; // Found a permutation of s1 in s2
            }
        }
        return false; // No permutation found
    }
};