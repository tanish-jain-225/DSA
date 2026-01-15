class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> nextGreaterMap;
        vector<int> result;

        // Preprocess nums2 to find the next greater element for each number
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if (s.empty()) {
                nextGreaterMap[nums2[i]] = -1;
            } else {
                nextGreaterMap[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }

        // Build the result for nums1 based on the preprocessed map
        for (int num : nums1) {
            result.push_back(nextGreaterMap[num]);
        }

        return result;
    }
};