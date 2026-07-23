// slightly better implementation(no global state variable):
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> color(numCourses, 0);
        
        // FIX 1: Pass by const reference to avoid massive memory copying
        for(const auto& v : prerequisites){
            adjList[v[0]].push_back(v[1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(color[i] == 0){
                // FIX 2: Evaluate the return value directly
                if (!dfs(i, adjList, color)) {
                    return false; // Cycle detected, immediately fail
                }
            }
        }
        return true;
    }

private:
    // FIX 2: Return a boolean. True = Safe, False = Cycle Detected
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& color){
        color[node] = 1; // 1: Visiting

        for(int nex : adj[node]){
            if(color[nex] == 0){
                // If a deeper recursion finds a cycle, cascade the failure upwards
                if (!dfs(nex, adj, color)) return false; 
            }
            else if(color[nex] == 1){
                return false; // Back edge detected! Graduation impossible.
            }
        }
        
        color[node] = 2; // 2: Safe/Exited
        return true;     // No cycles found from this node
    }
};