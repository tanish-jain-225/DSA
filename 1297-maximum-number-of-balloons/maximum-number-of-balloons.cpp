class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        unordered_map<char, int> f;

        for (int i = 0; i < n; i++) {
            f[text[i]]++;
        }

        string need = "balloon";
        int m = need.size();

        int res = INT_MAX;

        for (int i = 0; i < m; i++) {
            if (f.find(need[i]) != f.end()) {
                int freq = f[need[i]];

                // 'l' and 'o' are required twice - Handle Repeat Case
                if (need[i] == 'l' || need[i] == 'o') {
                    freq = freq / 2;
                }

                res = min(res, freq);
            } else {
                res = min(res, 0);
            }
        }

        return res;
    }
};