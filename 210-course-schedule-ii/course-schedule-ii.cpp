
class Solution {
public:
    bool isCyclicUtil(int node, vector<vector<int>>& adj, vector<bool>& visited,
                      vector<bool>& recStack, vector<int>& order) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, adj, visited, recStack, order)) {
                    return true;
                }
            } else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[node] = false;
        order.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            adj[prerequisite].push_back(course);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, adj, visited, recStack, order)) {
                    return {};
                }
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};