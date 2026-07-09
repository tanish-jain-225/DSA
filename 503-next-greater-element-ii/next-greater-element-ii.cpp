class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> res(n);

        stack<int> st;

        // Traverse twice to simulate circular array
        for (int i = 2 * n - 1; i >= 0; i--) {

            int idx = i % n;

            // Remove all smaller or equal elements
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            // Fill answer only during the second pass
            if (i < n) {
                if (st.empty())
                    res[idx] = -1;
                else
                    res[idx] = st.top();
            }

            // Push current element
            st.push(nums[idx]);
        }

        return res;
    }
};