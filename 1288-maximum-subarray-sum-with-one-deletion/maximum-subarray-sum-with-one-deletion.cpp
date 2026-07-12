class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n = arr.size();

        int noPower = arr[0]; // Maximum sum without deletion
        int power = 0;        // Maximum sum with one deletion
        int res = arr[0];

        for (int i = 1; i < n; i++) {

            // Save previous values
            int prevNoPower = noPower;
            int prevPower = power;

            // No deletion
            int v1 = arr[i];
            int v2 = prevNoPower + arr[i];

            // One deletion
            int v3 = prevPower + arr[i];
            int v4 = prevNoPower;

            noPower = max(v1, v2);
            power = max(v3, v4);

            res = max(res, max(noPower, power));
        }

        return res;
    }
};