class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        int i;

        stack<char> st;
        string res;

        for (i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            if (st.top() == s[i]) {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }

        while (!st.empty()) {
            char c = st.top();
            res.push_back(c);
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};