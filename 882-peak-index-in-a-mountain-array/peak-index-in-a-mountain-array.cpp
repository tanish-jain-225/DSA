class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int ans = -1;
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int guess = (low + high) / 2;

            if (arr[guess] < arr[guess + 1]) {
                ans = guess + 1;
                low = guess + 1;
            } else {
                ans = guess;
                high = guess - 1;
            }
        }

        return ans;
    }
};