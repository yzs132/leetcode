// source: https://leetcode.com/problems/trapping-rain-water/
// logic: if current height is increasing, fill up heights back to leftwall 

class Solution {
public:
    int trap(vector<int>& height) {
        if ( height.size()==0 ) return 0;
        
        int res = 0;
        int sum = height[0];
        int leftwall = 0;
        for(int i = 1; i < height.size(); i++){
            sum += height[i];   // accumulate the original heights
            if (height[i] > height[i-1]) {
                int newheight = (height[leftwall]<height[i]?height[leftwall]:height[i]);
                for (int ii=leftwall+1; ii<i; ii++){
                    if (height[ii] < newheight) height[ii] = newheight; 
                }
            }
            if (height[i] > height[leftwall]) leftwall = i;
        }
        
        for (int i=0; i<height.size(); i++){
            res += height[i];    
        }        
        
        return res-sum;
    }
};
