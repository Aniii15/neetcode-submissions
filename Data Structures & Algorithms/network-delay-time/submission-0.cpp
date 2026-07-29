
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //in every element v of minHeap v[1] = node, v[2] = parent, v[0] = distance
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        vector<vector<pair<int, int>>> adj(n+1); 
        for(const auto& vec : times){ // construct adjacency list
            int parent = vec[0];
            int child = vec[1];
            int wt = vec[2];
            adj[parent].push_back({child, wt});
        }

        vector<int> distances(n+1, 1e9);
        distances[k] = 0;

        minHeap.push({0, k, 0});

        while(!minHeap.empty()){
            auto vec = minHeap.top();
            int node = vec[1];
            int parent = vec[2];
            int dist = vec[0];
            minHeap.pop();

        if (dist > distances[node]) continue; // this is important too!
            
            for(const auto& [nex, wt] : adj[node]){
                if (distances[nex] > distances[node] + wt){
                    distances[nex] = distances[node] + wt;
                    minHeap.push({distances[nex], nex, node});
                }
            }

        }


        int m = *max_element(distances.begin()+1, distances.end());
        if(m != 1e9){
            return m;
        }
        else{
            return -1;
        }
    }
};
