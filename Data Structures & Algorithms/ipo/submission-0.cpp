class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> maxh;
        vector<pair<int,int>> projects;
        int n = profits.size();
        for(int i = 0; i<n; i++){
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        int i = 0;
        while(k>0){
            while(i < projects.size() && projects[i].first <= w){
                maxh.push(projects[i].second);
                i++;
            }

            if(maxh.empty()) break;

            w += maxh.top();
            maxh.pop();
            k--;
        }
        return w;
    }
};