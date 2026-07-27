// topological sort (kahn's algorithm)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj (numCourses); // just to convert the edges to an adjacency list

        for(const auto& v : prerequisites){
            adj[v[1]].push_back(v[0]);
        }

        vector<int> topo; // this stores our final answer;
        vector<int> indegree(numCourses, 0); // this stores the indegree of every node
        queue<int> q; // this is for our bfs-like traversal

        for(const auto& v : adj){ // this loop builds up our indegree vector
            for(int num : v){
                indegree[num]++;
            }
        }

        for(int i = 0; i < indegree.size(); i++){ // this pushes atleast one element in our q (if acyclic graph)
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for(int nex : adj[node]){
                indegree[nex]--;

                if(indegree[nex] == 0){
                    q.push(nex);
                }
            }
        }

        if(topo.size() != numCourses){ // cycle detected!
            return {};
        } 
        else{
            return topo;
        }  

    }
};
