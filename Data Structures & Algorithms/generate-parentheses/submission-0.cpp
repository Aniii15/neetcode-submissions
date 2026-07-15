// corrected by gemini
class Solution {
public:
    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        string temp = "";
        // Removed the dead-weight 'index' and 'n' parameters
        dfs(temp, n, n); 
        return ans;
    }

    void dfs(string& cur, int size1, int size2){

        // 1. BASE CASES
        if(size1 > size2){ // impossible (we placed too many ')' in the string)
            return;
        }
        if(size1 == 0 && size2 == 0){ // valid answer
            ans.push_back(cur);
            return;
        }

        // 2. CHOICES

        // choose from bucket1 (Only if we have '(' left!)
        if (size1 > 0) {
            cur.push_back('('); // action
            dfs(cur, size1 - 1, size2); // recurse
            cur.pop_back(); // backtrack
        }

        // choose from bucket2 (Only if we have ')' left!)
        if (size2 > 0) {
            cur.push_back(')'); // action
            dfs(cur, size1, size2 - 1); // recurse
            cur.pop_back(); // backtrack
        }
    }
};