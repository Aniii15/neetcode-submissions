class Solution {
public:
bool checkInclusion(string s1, string s2) {
    
    sort(s1.begin(), s1.end());
    unordered_set<string> s;

    for(int i = 0; i < s2.size()-s1.size()+1; i++){
        string str = s2.substr(i, s1.size());
        sort(str.begin(), str.end());
        s.insert(str);
    }

    for(string str : s){
        if(str == s1){
            return true;
        }
    }
    return false;
}
};
