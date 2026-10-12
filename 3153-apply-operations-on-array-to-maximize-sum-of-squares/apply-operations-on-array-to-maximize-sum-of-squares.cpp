
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> arr(k, 0);

        // Count how many numbers have each bit set
        for (int bit = 0; bit < 32; bit++) {
            int count = 0;

            for (int num : nums) {
                if (num & (1LL << bit)) {
                    count++;
                }
            }

            // Distribute this bit among k numbers
            for (int i = 0; i < min(k, count); i++) {
                arr[i] |= (1LL << bit);
            }
        }

        long long ans = 0;

        for (long long num : arr) {
            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};
