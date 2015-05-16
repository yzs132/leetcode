//Source: https://leetcode.com/problems/4sum/

//complexity: n^3

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort (nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size()<4) return res; 
        int previous1 = 0; int previous2 = 0;
        for (int i = 0; i<nums.size()-3;i++){ //1st number
            for (int j=i+1; j<nums.size()-2; j++){  // 2nd number
                int ii = j+1; int jj = nums.size()-1;
                int target1 = target - nums[i] - nums[j];
                while (ii<jj){
                    if (nums[ii]+nums[jj]>target1) jj--;
                    else if (nums[ii]+nums[jj]<target1) ii++;
                    else {
                        
                        vector<int> v { nums[i], nums[j], nums[ii], nums[jj] };
                        res.push_back (v);
                        
                        while(nums[ii+1]==nums[ii]) ii++;
                        while(nums[jj-1]==nums[jj]) jj--;

                        ii++;
                        jj--;
                    }
                }
                while(nums[j+1]==nums[j]) j++;
            }
            while (nums[i+1]==nums[i]) i++;
        }
        return res;
    }
};
