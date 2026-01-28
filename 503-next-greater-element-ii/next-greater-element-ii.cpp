class Solution {
public:
    vector<int> nextGreaterElements(
        vector<int>& nums) // Function to find the next greater elements in a
                           // circular array - TC: O(n), SC: O(n)
    {
        // Get the size of the input array
        int n = nums.size();
        vector<int> result(n, -1);

        stack<int> s; // Stack to keep indexes of nums array

        // We will traverse the array twice to simulate the circular nature
        for (int i = 2 * n - 1; i >= 0;
             i--) // Traverse from the end to the start
        {
            while (s.size() > 0 &&
                   nums[s.top()] <=
                       nums[i % n]) // Pop elements that are less than or equal
                                    // to current element
            {
                s.pop();
            }

            // If stack is empty, there is no greater element
            result[i % n] = s.empty() ? -1 : nums[s.top()];

            s.push(i % n); // Valid index pushed onto stack
        }

        // Return the result array
        return result;
    }
};