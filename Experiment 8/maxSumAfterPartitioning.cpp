#include <iostream>
#include <vector>
using namespace std;


int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();

    // dp[i] = max sum till index i
    vector<int> dp(n, 0);

    // iterate over each index
    for(int i = 0; i < n; i++) {
        int maxi = 0;  // maximum element in current partition
        int len = 0;   // length of current partition

        // try all partitions ending at i (size <= k)
        for(int j = i; j >= max(0, i - k + 1); j--) {
            len++;  // increase partition size

            // update maximum element in this partition
            maxi = max(maxi, arr[j]);

            // contribution of current partition
            int sum = maxi * len;

            // add previous result if exists
            if(j > 0) {
                sum += dp[j - 1];
            }

            // take maximum
            dp[i] = max(dp[i], sum);
        }
    }

    // final answer
    return dp[n - 1];
}

// Example usage
int main() {
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;

    cout << maxSumAfterPartitioning(arr, k);

    return 0;
}