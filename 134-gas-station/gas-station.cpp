class Solution {
public:
    int canCompleteCircuit(
        vector<int>& gas,
        vector<int>& cost) // Function to find the starting gas station index
    {
        int totalGas = 0;  // Total gas available
        int totalCost = 0; // Total cost required

        for (int val : gas) // Calculate total gas
            totalGas += val;

        for (int val : cost) // Calculate total cost
            totalCost += val;

        if (totalGas < totalCost) // If total gas is less than total cost, it's
                                  // impossible to complete the circuit
            return -1;

        // Unique solution exists, find the starting gas station index
        int start = 0;      // Starting gas station index
        int currentGas = 0; // Current gas in the tank
        for (int i = 0; i < gas.size(); i++) {
            currentGas += gas[i] - cost[i];

            // If current gas is negative, it means we cannot start from the
            // current starting point
            if (currentGas < 0) {
                start = i + 1;
                currentGas = 0;
            }
        }

        return start;
    }
};