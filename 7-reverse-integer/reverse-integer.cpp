class Solution {
public:
    int reverse(int ognum) {
        int reversedNum = 0; // Initialize reversed number
        while (ognum != 0) {
            int digit = ognum % 10; // Get the last digit
            if (reversedNum > INT_MAX / 10 || reversedNum < INT_MIN / 10) {
                return 0;
            }
            reversedNum =
                (reversedNum * 10) + digit; // Update the reversed number
            ognum /= 10; // Remove the last digit from the original number
        }
        return reversedNum; // Return the reversed number
    }
};