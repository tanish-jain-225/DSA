class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        while (true) {
            slow = nums[slow]; // move once
            fast = nums[fast]; // move one
            fast = nums[fast]; // move two

            if (slow == fast) // they meet first time
            {
                slow = 0;            // reset slow
                while (slow != fast) // till they meet again
                {
                    slow = nums[slow]; // move once
                    fast = nums[fast]; // move once
                }

                return slow; // got answer
            }
        }
        return -1; // not needed
    }
};