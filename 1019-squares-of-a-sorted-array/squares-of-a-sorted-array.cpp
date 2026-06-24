class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        vector<int> answer;

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }

        int ps = pos.size();
        int ns = neg.size();

        if (ps == 0) // negative Only
        {
            reverse(neg.begin(), neg.end()); // reverse
            for (int i = 0; i < ns; i++) {
                neg[i] = neg[i] * neg[i]; // Squared
                answer.push_back(neg[i]);
            }
            return answer;
        }

        if (ns == 0) // positive only
        {
            for (int i = 0; i < ps; i++) {
                pos[i] = pos[i] * pos[i]; // Squared
                answer.push_back(pos[i]);
            }
            return answer;
        }

        // square pos
        for (int i = 0; i < ps; i++) {
            pos[i] = pos[i] * pos[i]; // General Squared
        }

        // reverse neg
        reverse(neg.begin(), neg.end());
        // square neg
        for (int i = 0; i < ns; i++) {
            neg[i] = neg[i] * neg[i]; // General Squared
        }

        int first = 0;
        int second = 0;

        while (first < ps && second < ns) {
            if (pos[first] >= neg[second]) {
                answer.push_back(neg[second]);
                second++;
            } else {
                answer.push_back(pos[first]);
                first++;
            }
        }

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