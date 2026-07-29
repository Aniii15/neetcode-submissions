class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Apart from being the check to if a node exists, wordSet also acts as a visited array
        unordered_set<string> wordSet;
        for(const string& word : wordList){
            wordSet.insert(word);
        }
        queue<string> q;
        unordered_map<string, int> d; // Stores distances
        q.push(beginWord);
        wordSet.erase(beginWord); // critical line, we need to remove the beginWord too (just like others)
        d[beginWord] = 1;

        while (!q.empty()) {
            string word = q.front();
            if(word == endWord){
                return d[word];
            }
            q.pop();
            string original_word = word;

            // Loop through each character of the current word
            for (int i = 0; i < word.size(); i++) {
                char original_char = word[i];

                // Try all 26 letters
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;  // Substitute the character

                    // Is this generated word in our valid list?
                    if (wordSet.find(word) != wordSet.end()) {
                        q.push(word);
                        d[word] = d[original_word] + 1;
                        wordSet.erase(word);  // Mark as visited!
                    }
                }
                // Restore the original character before moving to the next index
                word[i] = original_char;
            }
        }

        return 0;
    }
};
