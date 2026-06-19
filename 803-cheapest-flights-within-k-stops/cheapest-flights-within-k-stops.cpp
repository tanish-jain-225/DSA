class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<pair<int, int>> adj[n];

        for (auto& it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);

        queue<vector<int>> q;

        q.push({0, src, 0});

        dist[src] = 0;

        while (!q.empty()) {

            auto curr = q.front();
            q.pop();

            int stops = curr[0];
            int node = curr[1];
            int cost = curr[2];

            if (stops > k)
                continue;

            for (auto& nbr : adj[node]) {

                int adjNode = nbr.first;
                int edgeWeight = nbr.second;

                if (cost + edgeWeight < dist[adjNode]) {

                    dist[adjNode] = cost + edgeWeight;

                    q.push({stops + 1, adjNode, cost + edgeWeight});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};