class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        typedef pair<int,int> P;
        priority_queue<P, vector<P>, greater<P>> minh;
        vector<vector<int>> v;
        vector<int> res;
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            v.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(v.begin(),v.end());
        int i = 0;
        long long currentTime = 0;
        while(i<n || !minh.empty()){
            
            if (minh.empty() && currentTime < v[i][0]) {
                currentTime = v[i][0];
            }

            while(i < n && v[i][0] <= currentTime){
                minh.push({v[i][1],v[i][2]});
                i++;
            }
            auto [processingTime, index] = minh.top();
            minh.pop();
            res.push_back(index);
            currentTime += processingTime;
        }
        return res;
    }
};