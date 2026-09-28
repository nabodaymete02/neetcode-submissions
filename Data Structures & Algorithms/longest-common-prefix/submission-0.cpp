class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string max = strs[0];
        for (int i=1; i<strs.size();i++){
            while(strs[i].find(max)!=0){
                max.pop_back();
                if(max.empty()) return "";
            }
        }
        return max;
    }
};