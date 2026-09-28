class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxh;
        for(int stone : stones){
            maxh.push(stone);
        }
        while(maxh.size()>1){
            int x = maxh.top();
            maxh.pop();
            int y = maxh.top();
            maxh.pop();
            if(x>y){
                maxh.push(x-y);
            }else{
                maxh.push(y-x);
            }
        }
        return maxh.top();
    }
};
