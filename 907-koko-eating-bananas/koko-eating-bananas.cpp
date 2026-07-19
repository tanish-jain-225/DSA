class Solution {
public:
    // Returns total hours required if Koko eats at 'speed' bananas/hour
    long long helper(vector<int>& piles, int n, int speed) {

        long long hours = 0;

        for (int i = 0; i < n; i++) {

            hours += piles[i] / speed;

            if (piles[i] % speed != 0) {
                hours++;
            }
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();

        // Minimum possible speed
        int low = 1;

        // Maximum possible speed = largest pile
        int high = -1;
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }

        int ans = -1;

        // Binary Search on answer
        while (low <= high) {

            int guess = low + (high - low) / 2;

            long long hours = helper(piles, n, guess);

            // Too slow
            if (hours > h) {
                low = guess + 1;
            }
            // Possible answer
            else {
                ans = guess;
                high = guess - 1;
            }
        }

        return ans;
    }
};