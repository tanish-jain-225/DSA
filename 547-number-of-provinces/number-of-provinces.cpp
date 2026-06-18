class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[city] = 1;

        for (int neighbour = 0; neighbour < isConnected.size(); neighbour++) {
            if (isConnected[city][neighbour] == 1 && !visited[neighbour]) {
                dfs(neighbour, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);

        int provinces = 0;

        for (int city = 0; city < n; city++) {
            if (!visited[city]) {
                dfs(city, isConnected, visited);
                provinces++;
            }
        }

        return provinces;
    }
};