class Solution {
private:
    bool isCyclicUtil(int node, vector<vector<int>>& adj, vector<bool>& visited,
                      vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, adj, visited, recStack)) {
                    return true;
                }
            } else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[node] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (const auto& prereq : prerequisites) {
            int course = prereq[0];
            int prerequisite = prereq[1];
            adj[prerequisite].push_back(course);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && isCyclicUtil(i, adj, visited, recStack)) {
                return false;
            }
        }

        return true;
    }
};