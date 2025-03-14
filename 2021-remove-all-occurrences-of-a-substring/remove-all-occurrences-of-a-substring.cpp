class Solution {
public:
    string removeOccurrences(string s2, string part) {
        while (s2.length() > 0 && s2.find(part) < s2.length()) {
            s2.erase(s2.find(part), part.length());
        }
        return s2;
    }
};