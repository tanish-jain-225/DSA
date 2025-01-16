class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 1; // Also here '0' is replaced by '1' since answer peak
                       // cannot be at start point
        int end = arr.size() -
                  2; // int end = arr.size() - 1; - Here '-2' is used to exclude
                     // last element as it cannot be answer as peak

        while (start <= end) {
            int mid = (start + ((end - start) / 2));

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid - 1] < arr[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};