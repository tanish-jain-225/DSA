class Solution {
public:
    bool correct(int have[], int needed[]) // incorrect when frequency we have is less then required/needed 
    { 
        for (int i = 0; i < 256; i++) {
            if (have[i] < needed[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int low = 0;
        int high = 0;

        int have[256] = {0};
        int needed[256] = {0};

        int result = INT_MAX;
        int start = 0;

        // Traverse and get frequency of characters of t
        for (char ch : t) {
            needed[ch]++;
        }

        for (high = 0; high < n; high++) {
            // Keep increasing till you reach needed answer
            have[s[high]]++;

            while (correct(have, needed)) // Call function and check if correct 
            {
                // Log answer
                int length = high - low + 1;
                if (result > length) {
                    result = length;
                    start = low;
                }

                // Shrink and check
                have[s[low]]--;
                low++;
            }
        }

        // Final answer decision
        if (result == INT_MAX)
            return "";
        return s.substr(start, result);

    }
};