class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> neg;
        vector<int> pos;
        vector<int> answer;

        // 1. Separate into negative and positive arrays
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }

        // 2. NOW get the accurate sizes after populating the vectors
        int ns = neg.size();
        int ps = pos.size();

        int first = 0;
        int second = 0;

        // 3. Handle edge cases where one side is completely empty
        if (ns == 0) {
            for (int i = 0; i < ps; i++) {
                answer.push_back(pos[i] * pos[i]);
            }
            return answer;
        }

        if (ps == 0) {
            // Reverse negatives because squaring them flips their sorted order
            reverse(neg.begin(), neg.end());
            for (int i = 0; i < ns; i++) {
                answer.push_back(neg[i] * neg[i]);
            }
            return answer;
        }

        // 4. If both exist, square the individual elements first to make
        // merging straightforward
        for (int i = 0; i < ps; i++)
            pos[i] = pos[i] * pos[i];
        for (int i = 0; i < ns; i++)
            neg[i] = neg[i] * neg[i];

        // Since neg was sorted from most negative to least negative (e.g., -3,
        // -1), squaring it makes it decreasing (9, 1). We must reverse it to
        // merge cleanly (1, 9).
        reverse(neg.begin(), neg.end());

        // 5. Classic Two-Pointer Merge (Identical to your loop logic)
        while (first < ps && second < ns) {
            if (pos[first] >= neg[second]) {
                answer.push_back(neg[second]);
                second++;
            } else {
                answer.push_back(pos[first]);
                first++;
            }
        }

        // Gather remaining elements
        while (first < ps) {
            answer.push_back(pos[first]);
            first++;
        }

        while (second < ns) {
            answer.push_back(neg[second]);
            second++;
        }

        return answer;
    }
};