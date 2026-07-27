class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left=0, right=n-1;

        int res = 0;

        while (left < right){
            int length = min (height[left] , height[right]);
            int width = right - left;
            int area = length * width;

            res = max(area, res);
            
            if(height[left] <= height[right])
                left++;
            else
                right--;
        }
        return res;
    }
};