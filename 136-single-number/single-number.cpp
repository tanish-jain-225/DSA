class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for(int val: nums)
        {
            answer = answer ^ val; // XOR
        }
        return answer;
    }
};
