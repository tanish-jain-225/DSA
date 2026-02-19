class Solution {
public:
    vector<int> maxSlidingWindow(
        vector<int>& nums,
        int k) // Function to find the maximum in each sliding window of size k
    {
        deque<int>
            dq; // will store the indices of the elements in the current window
        vector<int> result; // to store the maximum of each window

        // Analyze the first k elements to initialize the deque - 1st window
        for (int i = 0; i < k; i++) {
            // Remove elements from the back of the deque if they are smaller
            // than the current element
            while (!dq.empty() &&
                   nums[dq.back()] < nums[i]) // Non Viable elements are removed
                                              // from the back of the deque
            {
                dq.pop_back();
            }
            dq.push_back(i); // Add the current index to the back of the deque
        }

        for (int i = k; i < nums.size(); i++) {
            result.push_back(
                nums[dq.front()]); // The front of the deque is the largest
                                   // element of the previous window

            // Remove indices that are out of the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove elements from the back of the deque if they are smaller
            // than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i); // Add the current index to the back of the deque
        }

        result.push_back(
            nums[dq.front()]); // Add the maximum of the last window

        // Return the result vector containing the maximum of each sliding
        // window
        return result;
    }
};