class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> temp;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 1; i < n; i++) {

            int curr = nums[i - 1] + 1;

            while (curr < nums[i]) {
                temp.push_back(curr);
                curr++;
            }
        }

        return temp;
    }
};