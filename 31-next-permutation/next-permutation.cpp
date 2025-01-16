class Solution {
public:
    void nextPermutation(vector<int>& set) {
        // Step-1: find pivot
        int pivot = -1;
        int n = set.size();

        for (int i = n - 2; i >= 0; i--) {
            if (set[i] < set[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            reverse(set.begin(), set.end());
            return;
        }

        // Step-2: find next larger element to pivot
        for (int i = n - 1; i > pivot; i--) {
            if (set[i] > set[pivot]) {
                swap(set[i], set[pivot]);
                break;
            }
        }

        // Step-3: reverse (piv+1 to n-1)
        int i = pivot + 1, j = n - 1;
        while (i <= j) {
            swap(set[i++], set[j--]);
        }

        // Alternate - Step-3
        // reverse((set.begin() + pivot + 1), set.end());
    }
};