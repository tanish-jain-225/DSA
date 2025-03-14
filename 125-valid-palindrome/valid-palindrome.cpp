class Solution {
public:
    bool isAlphaNum(char ch) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int st = 0, en = s.size() - 1;
        while (st < en) {
            if (!isAlphaNum(s[st])) {
                st++;
                continue;
            }
            if (!isAlphaNum(s[en])) {
                en--;
                continue;
            }
            if (tolower(s[st]) != tolower(s[en]))
                return false;
            st++;
            en--;
        }
        return true;
    }
};