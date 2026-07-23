class Solution {
public:
    bool tracker = true;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> color (numCourses, 0);
        for(vector<int> v : prerequisites){
            adjList[v[0]].push_back(v[1]);
        }

        for(int i = 0; i < adjList.size(); i++){
            if(color[i] == 0){
                dfs(i, adjList, color);
            }
            if (tracker == false) return false;
        }
        return true;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<int>& color){
        if (tracker == false) return; 
        color[node] = 1;

        for(int nex : adj[node]){
            if(color[nex] == 0){
                dfs(nex, adj, color);
            }
            else if(color[nex] == 1){
                tracker = false;
            }
        }
        color[node] = 2;
    }
};
