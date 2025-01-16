class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int idx = m + n - 1; // Start from the end of A's allocated size
        int i = m - 1;       // Last valid element of A
        int j = n - 1;       // Last valid element of B

        // Merge A and B starting from the largest elements
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j]) {
                A[idx--] = A[i--];
            } else {
                A[idx--] = B[j--];
            }
        }

        // If B still has elements, copy them
        while (j >= 0) {
            A[idx--] = B[j--];
        }
    }
};