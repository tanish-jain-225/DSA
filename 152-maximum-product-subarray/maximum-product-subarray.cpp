class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int best = nums[0];
        int worst = nums[0];
        int answer = nums[0];

        for (int i = 1; i < n; i++) {

            int prevBest = best;
            int prevWorst = worst;

            int v1 = nums[i];
            int v2 = prevBest * nums[i];
            int v3 = prevWorst * nums[i];

            best = max(v1, max(v2, v3));
            worst = min(v1, min(v2, v3));

            answer = max(answer, best);
        }

        return answer;
    }
};