class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0; // Pointer for the position to write compressed characters

        for (int i = 0; i < n; i++) {
            char currentChar = chars[i];
            int count = 1;

            // Count consecutive occurrences of currentChar
            while (i + 1 < n && chars[i + 1] == currentChar) {
                i++;
                count++;
            }

            chars[idx++] = currentChar; // Add the character
            if (count > 1)              // Only add count if it's greater than 1
            {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[idx++] = c;
                }
            }
        }
        return idx;
    }
};