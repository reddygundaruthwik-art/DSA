class Solution {
public:
    int countSubarrays(vector<int>& nums, long long maxSum) {
        int subarrays = 1;
        long long sum = 0;

        for (int num : nums) {
            if (sum + num > maxSum) {
                subarrays++;
                sum = num;
            } else {
                sum += num;
            }
        }

        return subarrays;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;

        for (int num : nums) {
            high += num;
        }

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            int requiredSubarrays = countSubarrays(nums, mid);

            if (requiredSubarrays <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};