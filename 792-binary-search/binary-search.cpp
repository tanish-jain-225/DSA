class Solution {
public:
    // Helper function for recursion
    int binarySearchHelper(vector<int>& arr, int target, int st, int end) {
        // Base case - if the search space is empty
        if (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] == target) {
                return mid; // Target found
            } else if (arr[mid] < target) {
                return binarySearchHelper(arr, target, mid + 1,
                                          end); // Search in the right half
            } else {
                return binarySearchHelper(arr, target, st,
                                          mid - 1); // Search in the left half
            }
        } else {
            return -1; // Target not found
        }
    }

    // Parent function
    int search(vector<int>& arr, int target) {
        int st = 0;
        int end = arr.size() - 1;

        // Helper function for recursion
        return binarySearchHelper(arr, target, st, end);
    }
};