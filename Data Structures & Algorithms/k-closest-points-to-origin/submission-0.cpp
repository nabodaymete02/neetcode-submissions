class Solution {
public:
    typedef pair<int, pair<int,int>> ppi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<ppi> maxh;
        for(auto point : points){
            maxh.push({(point[0]*point[0] + point[1]*point[1]),{point[0],point[1]}});
            if(maxh.size()>k) maxh.pop();
        }
        vector<vector<int>> res;
        while(maxh.size()>0){
            res.push_back({maxh.top().second.first, maxh.top().second.second});
            maxh.pop();
        }
        return res;
    }
};
