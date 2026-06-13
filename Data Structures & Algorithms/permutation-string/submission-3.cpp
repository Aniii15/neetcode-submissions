class Solution {
public:
bool checkInclusion(string s1, string s2) {
    
    
    
    map<char, int> hash_map1;

    for (char c : s1){
        hash_map1[c]++;
    }
    string str1 = "";
    for(auto it = hash_map1.begin(); it != hash_map1.end(); it++){
        // cout <<it-> first << " " << it -> second << endl;
        str1 = str1 + to_string((*it).first) + to_string((*it).second) + '#' ;
    }

    for(int i = 0; i < s2.size()-s1.size()+1; i++){
        map<char,int> hash_map2;

        string str = s2.substr(i, s1.size());
        // cout << str << endl;
        for (char c : str){
            hash_map2[c]++;
        }
        string str2 = "";
        for(auto itr = hash_map2.begin(); itr != hash_map2.end(); itr++){
            // cout <<itr-> first << " " << itr -> second << endl;
            str2 = str2 + to_string((*itr).first) + to_string((*itr).second) + '#' ;

        }

        if (str1 == str2){
            return 1;
        }
    }
    return 0;

}
};
