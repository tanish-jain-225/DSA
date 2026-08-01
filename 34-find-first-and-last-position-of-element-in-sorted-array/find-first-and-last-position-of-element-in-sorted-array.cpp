class Solution {
public:
    int first(vector<int>& a, int x) {
        int n = a.size();
        int low = 0;
        int high = n - 1;
        int res = -1;

        while (low <= high) {
            int guess = (low + high) / 2;
            if (a[guess] > x) {
                high = guess - 1;
            } else if (a[guess] < x) {
                low = guess + 1;
            } else {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }

    int last(vector<int>& a, int x) {

        int n = a.size();
        int low = 0;
        int high = n - 1;
        int res = -1;

        while (low <= high) {
            int guess = (low + high) / 2;
            if (a[guess] > x) {
                high = guess - 1;
            } else if (a[guess] < x) {
                low = guess + 1;
            } else {
                res = guess;
                low = guess + 1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstpos = first(nums, target);
        int lastpos = last(nums, target);

        return {firstpos, lastpos};
    }
};