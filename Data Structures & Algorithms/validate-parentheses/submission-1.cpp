class Solution {
public:
bool isValid(string s) {
    
    unordered_map<char, int> m = {{'{', 1}, {'[', 2}, {'(', 3}, {'}', -1}, {']', -2}, {')', -3}};

    stack<char> openers;
    for (char c : s)
    {
        if (m[c] > 0)
        {
            openers.push(c);
        }
        else
        {
            if (!openers.empty() && (m[c] + m[openers.top()] == 0))
            {
                openers.pop();
            }
            else
            {
                return 0;
            }
        }
    }
    if (openers.empty())
    {
        return 1;
    }
    return 0;
    
}
};
