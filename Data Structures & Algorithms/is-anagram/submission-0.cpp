class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um1;
        for(char c : s){
            um1[c]++;
        }
        for(char c : t){
            um1[c]--;
        }
        for(auto &i : um1){
            if(i.second) return false;
        }

        return true;

    }
};
