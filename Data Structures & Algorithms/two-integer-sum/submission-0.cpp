class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoS;
        int i,j;
        for(i; i< nums.size()-1; i++){
            for( j=i+1; j< nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    twoS.push_back(i);
                    twoS.push_back(j);
                    break;
                }
            }
        }
        return twoS;
    }
};
