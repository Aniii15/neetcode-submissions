class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // adj[i] contains pairs where for each pr, pr.first = adjacent_vertex and pr.second =
        // edge_weight
        vector<vector<pair<int, int>>> adj(n);
        for (auto& v : flights) {
            adj[v[0]].push_back({v[1], v[2]});
        }

        // every member in the costs vector is the best+feasible cost to reach that node
        vector<int> costs(n, 1e9);
        costs[src] = 0 ;

        // for every vec in minHeap, vec[0] = stop_count, vec[1] = total_cost, vec[2] = node
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, 0, src});

        while (!minHeap.empty()) {
            const auto vec = minHeap.top();
            int stop_count = vec[0];
            int total_cost = vec[1];
            int node = vec[2];
            minHeap.pop();

            if (stop_count > k) {
                break;
            }

            for (const auto& pr : adj[node]) {
                int nex = pr.first;    // adjacent_vertex
                int cost = pr.second;  // edge_weight

                if (total_cost + cost < costs[nex]) {
                    minHeap.push({stop_count + 1, total_cost + cost, nex});
                    costs[nex] = total_cost + cost;
                }
            }
        }

        if (costs[dst] != 1e9) {
            return costs[dst];
        } else {
            return -1;
        }
    }
};
