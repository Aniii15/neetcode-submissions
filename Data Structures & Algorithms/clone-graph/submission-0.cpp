/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)  return nullptr; // for a tricky test-case

        unordered_map<Node*, Node*> table;
        dfs(node, table); // run the dfs to populate the hash_map(table)

        // use square brackets for iterating through the unordered_map for key-value pair!!
        for(auto& [nd, copy] : table){ 
            vector<Node*> neighbors2;
            for(Node* neig : nd->neighbors){
                neighbors2.push_back(table[neig]);
            }
            copy->neighbors = neighbors2;
        }

        return table[node];
    }
    
    // using this dfs, let's try to copy all nodes (only nodes) in a hash map, then, we'll figure out the connections
    // we'll use this table itself to work as a 'visited' array for us!
    void dfs(Node* node, unordered_map<Node*, Node*> &table)
{
    // base case:
    if (table.find(node) != table.end()) return;

    Node* temp = new Node(node->val);
    table[node] = temp;

    // for its 'neighbors':
    for (auto it : node->neighbors)
    {
        dfs(it, table);
    }
}
};
