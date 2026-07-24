class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> color(n, 0);

        // Build the two-way undirected graph
        for(const auto& v : edges){
            adjList[v[1]].push_back(v[0]);
            adjList[v[0]].push_back(v[1]);
        }

        // Trap 1: Cycle Detection (Start DFS at node 0, with parent -1)
        if (!dfs(adjList, color, 0, -1)) {
            return false; // A real cycle was found!
        }

        // Trap 2: The Forest Check
        for(int c : color){
            if(c == 0){
                return false; // Some nodes were completely unreachable
            }
        }

        return true;
    }

private:
    bool dfs(vector<vector<int>>& adj, vector<int>& color, int v, int parent){
        color[v] = 1; // Visiting

        for(int nex : adj[v]){
            // The magic check: Ignore the node we JUST came from
            if (nex == parent) continue; 

            if(color[nex] == 0) {
                if (!dfs(adj, color, nex, v)) return false; 
            }
            else if(color[nex] == 1) {
                // If it's state 1, AND it's not our parent... it's a true Back Edge!
                return false; 
            }
        }
        color[v] = 2; // Safe
        return true;
    }
};