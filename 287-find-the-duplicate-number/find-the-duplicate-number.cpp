class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Finding the intersection point in the cycle
        do {
            slow = nums[slow];       // Move slow by 1 step
            fast = nums[nums[fast]]; // Move fast by 2 steps
        } while (slow != fast);

        // Phase 2: Finding the entrance to the cycle
        slow = nums[0];

        // Move both pointers at the same speed
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow; // The duplicate number
    }
};