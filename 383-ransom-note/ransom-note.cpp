class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = magazine.size();
        unordered_map<char, int> f;

        for (int i = 0; i < n; i++) {
            f[magazine[i]]++;
        }

        int m = ransomNote.size();

        for (int i = 0; i < m; i++) {
            if (f.find(ransomNote[i]) == f.end()) {
                return false;
            } else {
                f[ransomNote[i]]--;
                if (f[ransomNote[i]] == 0) {
                    f.erase(ransomNote[i]);
                }
            }
        }

        return true;
    }
};