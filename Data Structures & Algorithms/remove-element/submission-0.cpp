class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> num1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=val) num1.push_back(nums[i]);
        }
        for(int i=0; i<num1.size(); i++){
            nums[i]=num1[i];
        }
        return num1.size();
    }
};