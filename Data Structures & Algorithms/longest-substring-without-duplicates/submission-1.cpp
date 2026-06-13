class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    if (s.size() < 1){
        return 0;
    }

    vector<char> v;

    int curr, best = 0;

    int left = 0;
    for(int right = 0; right<s.size(); right++){
        auto it = find(v.begin(), v.end(), s[right]);
        if (it != v.end()){
            v.erase(v.begin(), it+1);
            left = right;
        }
        v.push_back(s[right]);
        curr = v.size(); 
        best = max(curr, best);
    }
    return best;

    }
};
