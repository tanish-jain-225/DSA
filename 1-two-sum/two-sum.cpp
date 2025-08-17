class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> num_map; // Stores number and its index
        vector<int> result;
        for (int i = 0; i < arr.size(); i++) {
            int first = arr[i];
            int second = target - first; // Find the complement
            // Check if complement exists in the map
            if (num_map.find(second) != num_map.end()) {
                result.push_back(i);
                result.push_back(num_map[second]);
                break;
            }
            // Store the current number and its index
            num_map[first] = i;
        }
        // Return empty vector if no pair found
        return result;
    }
};