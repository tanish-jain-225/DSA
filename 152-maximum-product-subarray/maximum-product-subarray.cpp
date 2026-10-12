class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        // Initial vars
        int n = nums.size();
        int ans = nums[0];
        
        // Best and Worst cases
        int bestEnd = nums[0];
        int worstEnd = nums[0];

        // Entire Loop
        for(int i=1; i<n; i++)
        {
            // versions
            int v1 = nums[i];
            int v2 = bestEnd * nums[i];
            int v3 = worstEnd * nums[i];

            // Updates 
            bestEnd = max(v1, max(v2, v3));
            worstEnd = min(v1, min(v2, v3));

            // final best of all - optimisation
            ans = max(ans, max(bestEnd, worstEnd));
        }

        // return final optimised best product
        return ans;

    }
};