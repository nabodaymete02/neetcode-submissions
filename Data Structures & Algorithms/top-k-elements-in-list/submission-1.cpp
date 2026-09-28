class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> solution;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(const auto& [element, frequency] : mp){
            bucket[frequency].push_back(element); 
        }
        for(int i = bucket.size()-1; i>= 0 && solution.size()<k; i--){
            for(int num : bucket[i]){
                solution.push_back(num);
                if(solution.size()==k) return solution;
            }
        }
        return solution;
    }
};
