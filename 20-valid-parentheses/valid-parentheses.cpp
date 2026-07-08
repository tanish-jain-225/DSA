class Solution {
public:
    bool isValid(string s) {

        int n = s.size();

        stack<char> st;

        for (int i = 0; i < n; i++) {

            // Opening brackets
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }

            // Closing brackets
            else {

                // No opening bracket available
                if (st.empty())
                    return false;

                char open = st.top();

                // Matching pair
                if ((open == '(' && s[i] == ')') ||
                    (open == '{' && s[i] == '}') ||
                    (open == '[' && s[i] == ']')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // Stack should be empty
        return st.empty();
    }
};