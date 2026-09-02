class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0;
        int high = n1;

        int total = n1 + n2;
        int leftSize = (total + 1) / 2;

        while (low <= high) {

            int cut1 = (low + high) / 2;
            int cut2 = leftSize - cut1;

            // Elements just outside the partition
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // Correct partition
            if (l1 <= r2 && l2 <= r1) {

                // Odd total number of elements
                if (total % 2 == 1) {
                    return max(l1, l2);
                }

                // Even total number of elements
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            // We have taken too many elements from nums1
            else if (l1 > r2) {
                high = cut1 - 1;
            }

            // We need to take more elements from nums1
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};