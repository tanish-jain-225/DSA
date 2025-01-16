class Solution {
public:
    int search(vector<int>& arr, int target) {
        // Initial data
        int count = arr.size();
        int start = 0;
        int end = (count - 1);

        // BS Operations as per sorted sides
        while (start <= end) {
            int mid = (start + ((end - start) / 2));

            if (arr[mid] == target) {
                // Result when finally every step is checked
                return mid;
            }

            if (arr[start] <= arr[mid]) {
                // Left Sorted
                if (arr[start] <= target && target <= arr[mid]) {
                    end = (mid - 1);
                } else {
                    start = (mid + 1);
                }
            } else {
                // Right Sorted
                if (arr[mid] <= target && target <= arr[end]) {
                    start = (mid + 1);
                } else {
                    end = (mid - 1);
                }
            }
        }
        // If after all processes still target not found return -1 indicating
        // not found
        return -1;
    }
};