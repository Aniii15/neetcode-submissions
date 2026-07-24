class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> color(n, 0);

        for(const auto& pr : edges){
            adjList[pr[0]].push_back(pr[1]);
            adjList[pr[1]].push_back(pr[0]);
        }

        int ct = 0;

        for(int i = 0; i < adjList.size(); i++){
            if(color[i] == 0){
                dfs(i, color, adjList);
                ct++;
            }
        }

        return ct;
    }

    void dfs(int v, vector<int>& color, vector<vector<int>>& adj){
        color[v] = 1;

        for(int nex : adj[v]){
            if(color[nex] == 0){
                dfs(nex, color, adj);
            }
        }
        color[v] = 2;
    }
};
