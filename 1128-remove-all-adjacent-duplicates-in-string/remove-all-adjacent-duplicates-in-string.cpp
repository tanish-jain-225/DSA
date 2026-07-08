class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
        string res;

        for (int i = 0; i < n; i++) // Fill stack
        {
            if (st.empty()) // First iteration
            {
                st.push(s[i]);
                continue;
            }

            if (st.top() == s[i]) // pop condition
            {
                st.pop();
                continue;
            }

            st.push(s[i]); // default stack pushes
        }

        while (!st.empty()) // empty stack till zeroed
        {
            res.push_back(st.top()); // store answer
            st.pop();       // remove current item
        }

        // Since answer is reversed, to get back to og state
        reverse(res.begin(), res.end());

        // final answer return
        return res;
    }
};