class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n -1) return false; // very few impostors will survive this brutal test

        vector<vector<int>> adjList (n);
        vector<int> color (n, 0);

        for(const auto& v : edges){
            adjList[v[1]].push_back(v[0]);
            adjList[v[0]].push_back(v[1]);
        }

        dfs(adjList, color, 0);

        for(int c : color){
            if(c == 0){
                return false;
            }
        }

        return true;
    }

    void dfs(vector<vector<int>>& adj, vector<int>& color, int v){
        color[v] = 1;

        for(int& nex : adj[v]){
            if(color[nex] == 0) {
                dfs(adj, color, nex);
            }
        }
        color[v] = 2;
    }
};