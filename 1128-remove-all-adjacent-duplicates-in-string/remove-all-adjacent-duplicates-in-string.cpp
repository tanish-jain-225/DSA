
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
        string res;

        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top() == s[i]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        while (!st.empty()) {
            int c = st.top();
            st.pop();
            res.push_back(c);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
