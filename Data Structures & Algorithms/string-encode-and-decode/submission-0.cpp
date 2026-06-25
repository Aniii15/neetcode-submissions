class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string str : strs){
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> final;
        string len = "";
        for(int i = 0; i < s.size(); ){
            if(s[i] != '#'){
                len += s[i];
                i++;
            }
            else{
                i++;
                int length = stoi(len);
                len = "";
                string cur = "";
                for(int j = 0; j < length; j++){
                    cur += s[i];
                    i++;
                }
                final.push_back(cur);
            }

        } 
        return final;

    }
};
