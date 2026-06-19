class Solution {
public:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin,
             vector<int>& low, vector<vector<int>>& adj,
             vector<vector<int>>& bridges) {

        vis[node] = 1;

        tin[node] = low[node] = timer++;

        for (auto neighbour : adj[node]) {

            if (neighbour == parent)
                continue;

            if (!vis[neighbour]) {

                dfs(neighbour, node, vis, tin, low, adj, bridges);

                low[node] = min(low[node], low[neighbour]);

                if (low[neighbour] > tin[node]) {
                    bridges.push_back({node, neighbour});
                }
            } else {

                low[node] = min(low[node], tin[neighbour]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n, -1);
        vector<int> low(n, -1);

        vector<vector<int>> bridges;

        dfs(0, -1, vis, tin, low, adj, bridges);

        return bridges;
    }
};