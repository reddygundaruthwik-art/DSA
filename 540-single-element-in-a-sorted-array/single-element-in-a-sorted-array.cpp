class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Make mid even
            if (mid % 2 == 1) {
                mid--;
            }

            // Pair is correct: single element is on the right
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            }
            // Pair is broken: single element is on the left
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};