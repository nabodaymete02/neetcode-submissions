class Solution {
public:
    bool isValid(string s) {
        vector<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push_back(s[i]);
            }
            else if(!st.empty() && s[i] == ')' && st.back()=='('){
                st.pop_back();
            }
            else if(!st.empty() && s[i] == '}' && st.back()=='{'){
                st.pop_back();
            }
            else if(!st.empty() && s[i] == ']' && st.back()=='['){
                st.pop_back();
            }
            else st.push_back(s[i]);
        }
        return st.empty();
    }
};
