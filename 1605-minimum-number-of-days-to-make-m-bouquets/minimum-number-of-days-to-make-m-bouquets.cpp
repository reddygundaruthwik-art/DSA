class Solution {
public:

    bool possible(vector<int>& arr, int day, int m, int k) {
        int cnt = 0;
        int noOfBouquets = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                cnt++;
            } 
            else {
                noOfBouquets += cnt / k;
                cnt = 0;
            }
        }

        // Count bouquets from the last consecutive sequence
        noOfBouquets += cnt / k;

        return noOfBouquets >= m;
    }

    int rosegarden(vector<int>& arr, int m, int k) {
        long long val = 1LL * m * k;

        if (val > arr.size()) {
            return -1;
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }

        int low = mini;
        int high = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(arr, mid, m, k)) {
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        return low;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        return rosegarden(bloomDay, m, k);
    }
};