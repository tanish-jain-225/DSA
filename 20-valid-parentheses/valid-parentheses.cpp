class Solution {
public:
    bool isValid(string s) { // using stack

        // stack to keep track of opening brackets
        stack<char> st;

        // length of the string
        int n = s.length();

        // iterate through each character in the string
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch); // push opening brackets onto stack
            } else {
                // if stack is empty when we encounter a closing bracket, return
                // false - no matching opening bracket
                if (st.empty())
                    return false;

                if ((ch == ')' && st.top() == '(') ||
                    (ch == '}' && st.top() == '{') ||
                    (ch == ']' && st.top() == '[')) // ch matches with st.top()
                {
                    st.pop(); // pop the matching opening bracket from stack
                } else {
                    return false; // brackets do not match
                }
            }
        }
        return st.empty(); // if stack is empty, all brackets matched;
                           // otherwise, return false
    }
};