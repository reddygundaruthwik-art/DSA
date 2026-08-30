class Solution {
public:

    int countsubarray(vector<int>& nums, int subarray){
        int panters = 1; long long time = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            if(time + nums[i] <= subarray){
                time = time + nums[i];
            }

            else{
                panters++;
                time = nums[i];
            }
        }
        return panters;
    }
    int splitArray(vector<int>& nums, int k) {
        int ans = -1;
        int n = nums.size();
        if(k > n){
            return -1;
        }

        long low = *max_element(nums.begin(), nums.end());
        long high = 0;
        for(int i = 0; i < n; i++){
            high = high + nums[i];
        }

        while(low <= high){
            long long mid = low + (high - low)/2;
            int cntsubarray = countsubarray(nums, mid);
            if(cntsubarray <= k){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};