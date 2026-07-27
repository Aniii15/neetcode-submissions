class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<char>> adj(26);
        vector<int> color(26, 0);
        unordered_set<int> chars; // All unique characters present in input
        vector<char> characters;

        // Step 1: Collect ALL unique characters first
        for (const string& word : words) {
            for (char c : word) {
                chars.insert(c - 'a');
            }
        }

        // Step 2: Build the Adjacency List by comparing adjacent words
        for (int i = 0; i < (int)words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            // THE ALIEN BOY TRAP FIX:
            // If w1 is longer than w2 AND w2 is a prefix of w1 (e.g. "abc" comes before "ab"),
            // the dictionary is invalid by definition!
            if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) {
                return "";
            }

            // Find the VERY FIRST differing character
            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j]);
                    break; // Only the FIRST mismatch tells us the relative ordering!
                }
            }
        }

        // Step 3: Run DFS on all unique characters
        for (int i : chars) {
            if (color[i] == 0) {
                char node = static_cast<char>(i + 'a');
                dfs(node, color, adj, characters);

                if (!flag) {
                    return ""; // Cycle detected!
                }
            }
        }

        // Step 4: Reverse post-order array to get final Topological Sort
        string final;
        for (int i = characters.size() - 1; i >= 0; i--) {
            final.push_back(characters[i]);
        }

        return final;
    }

    bool flag = true; // Tracks graph validity (false if cycle detected)

    void dfs(char node, vector<int>& color, vector<vector<char>>& adj, vector<char>& characters) {
        if (!flag) return;

        color[node - 'a'] = 1; // Mark as Visiting

        for (char nex : adj[node - 'a']) {
            if (color[nex - 'a'] == 0) {
                dfs(nex, color, adj, characters);
            } else if (color[nex - 'a'] == 1) {
                flag = false; // Back-edge detected! Invalid alien dictionary.
                return;
            }
        }

        color[node - 'a'] = 2; // Mark as Visited
        characters.push_back(node);
    }
};