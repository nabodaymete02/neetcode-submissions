class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> st;
        int n = temperatures.size();
        vector<int> result(n, 0);
        for(int i = 0; i < n; i++){
            while(!st.empty() && temperatures[st.back()]<temperatures[i]){
                result[st.back()] = i - st.back();
                st.pop_back();
            }
            st.push_back(i);
        }
        return result;
    }
};
