class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;

        for (int i = n - 2; i >= 0;
             i--) // ready stack before last element index i.e. i-2 to 0
        {
            st.push(nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                res[i] = -1;
            } else {
                res[i] = st.top();
            }

            st.push(nums[i]);
        }

        return res;
    }
};