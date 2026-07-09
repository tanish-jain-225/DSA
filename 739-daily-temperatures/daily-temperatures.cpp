class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        vector<int> res(n);

        stack<int> st; // Store indices

        res[n - 1] = 0;
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--) {

            // Remove all temperatures that are not warmer
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // No warmer day exists
            if (st.empty()) {
                res[i] = 0;
            } else {
                res[i] = st.top() - i;
            }

            // Push current index
            st.push(i);
        }

        return res;
    }
};