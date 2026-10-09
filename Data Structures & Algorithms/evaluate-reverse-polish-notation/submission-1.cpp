class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> st;
        for(int i = 0; i < tokens.size(); i++){
           if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                st.push_back(tokens[i]);
            }
            else{
                int b = stoi(st.back());
                st.pop_back();
                int a = stoi(st.back());
                st.pop_back();
                int c;
                if(tokens[i] == "+") c = a+b;
                else if(tokens[i] == "-") c = a-b;
                else if(tokens[i] == "*") c = a*b;
                else if(tokens[i] == "/") c = a/b;
                st.push_back(to_string(c));
            }
        }
        return stoi(st.back());
    }
};
