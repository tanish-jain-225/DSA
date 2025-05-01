class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end()); // Reverse the entire string
        int n = s.length();
        string word = "";
        string result = "";

        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                reverse(word.begin(), word.end()); // Reverse each word
                if (result.empty())
                    result = word;
                else
                    result += " " + word;
                word = ""; // Reset word
            }
        }

        // Handle the last word (if any)
        if (!word.empty()) {
            reverse(word.begin(), word.end());
            if (result.empty())
                result = word;
            else
                result += " " + word;
        }

        return result;
    }
};