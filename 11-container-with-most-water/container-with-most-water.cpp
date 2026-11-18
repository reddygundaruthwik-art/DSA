class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxwater = 0;

        int i = 0;
        int j = n - 1;

        while(i < j){
            int area = (j - i) * min(height[i], height[j]);
            maxwater = max(area, maxwater);

            if(height[i] < height[j]){
                i++;
            }

            else{
                j--;
            }
        }
        return maxwater;
    }
};