class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> color(numCourses, 0);
        vector<int> result; // This array replaces the need for time_out

        // Step 1: Build the graph forward (Prerequisite -> Course)
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); 
        }

        // Step 2: Run the 3-Color DFS on all unvisited nodes
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == 0) {
                if (!dfs(i, adj, color, result)) {
                    return {}; // Cycle detected: return an empty array
                }
            }
        }

        // Step 3: Reverse the result to get the valid Topological Sort
        reverse(result.begin(), result.end());
        return result;
    }

private:
    bool dfs(int node, const vector<vector<int>>& adj, vector<int>& color, vector<int>& result) {
        color[node] = 1; // Mark as Visiting

        for (int neighbor : adj[node]) {
            if (color[neighbor] == 0) {
                if (!dfs(neighbor, adj, color, result)) return false;
            } 
            else if (color[neighbor] == 1) {
                return false; // Back edge (Cycle) detected
            }
        }

        color[node] = 2; // Mark as Safe / Exited
        
        // This is the magic line! Pushing a node as we exit the recursion 
        // automatically sorts the graph by its exit time.
        result.push_back(node); 
        
        return true;
    }
};