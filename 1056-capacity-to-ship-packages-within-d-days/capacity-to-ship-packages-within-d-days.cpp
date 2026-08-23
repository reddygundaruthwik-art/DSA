class Solution {
public:
    int requrieddays(vector<int> &weights, int capacity){
        int load = 0; int reqdays = 1;
        for(int i = 0; i < weights.size(); i++){
            if(load + weights[i] > capacity){
                reqdays++;
                load = weights[i];
            }
            else{
                load = load + weights[i];
            }
        }
        return reqdays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(int i = 0; i < weights.size(); i++){
            high = high + weights[i];
        }
        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            int reqdays = requrieddays(weights, mid);

            if(reqdays <= days){
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