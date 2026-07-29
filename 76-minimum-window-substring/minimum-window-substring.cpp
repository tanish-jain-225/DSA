class Solution {
public:
    // Returns true if current window contains all required characters
    bool helper(unordered_map<char, int>& fs, unordered_map<char, int>& ft) {

        for (auto i : ft) {

            char c = i.first;
            int need = i.second;

            if (fs[c] < need) {
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {

        unordered_map<char, int> fs;
        unordered_map<char, int> ft;

        int ss = s.size();
        int ts = t.size();

        // Frequency of target string
        for (int i = 0; i < ts; i++) {
            ft[t[i]]++;
        }

        int low = 0;

        int minLen = INT_MAX;
        int start = -1;

        for (int high = 0; high < ss; high++) {

            // Expand window
            fs[s[high]]++;

            // Shrink window while it is valid
            while (helper(fs, ft)) {

                int len = high - low + 1;

                if (len < minLen) {
                    minLen = len;
                    start = low;
                }

                fs[s[low]]--;

                if (fs[s[low]] == 0) {
                    fs.erase(s[low]);
                }

                low++;
            }
        }

        if (start == -1) {
            return "";
        }

        return s.substr(start, minLen);
    }
};