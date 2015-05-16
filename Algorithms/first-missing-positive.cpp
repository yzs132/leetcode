//source: https://leetcode.com/problems/first-missing-positive/

//complexity: n 

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int size = nums.size();
        
        vector<bool> foo(size+1);
        foo[0] = true;
        
        for (int i=0; i<nums.size(); i++){
            if (nums[i] > 0 && nums[i] <= size) foo[nums[i]] = true;
        }
        
        for (int i=1; i < size+1; i++){
            if (foo[i] == false) return i;
        }
        
        return size+1;
    }
    
};
