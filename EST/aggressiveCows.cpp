//Problem statemet : given n cows and m stalls, find the minimum distance between cows such that all cows can be placed in the stalls. The distance between two cows is defined as the absolute difference of their positions in the stalls.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& stalls, int cows, int distance) {
    int count = 1; 
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= distance) {
            count++;
            lastPosition = stalls[i];
            if (count == cows) {
                return true; 
            }
        }
    }
    return false; 
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end()); 
    int left = 1; 
    int right = stalls.back() - stalls[0]; 
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (isPossible(stalls, cows, mid)) {
            result = mid; 
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m; 
    vector<int> stalls(m);
    
    for (int i = 0; i < m; i++) {
        cin >> stalls[i]; 
    }

    cout << aggressiveCows(stalls, n) << endl; 
    return 0;
}


// Time Complexity : O(m log m + m log (max_position - min_position)) where m is the number of stalls. The first term is for sorting the stalls, and the second term is for the binary search on the distance.
// Space Complexity : O(1) if we ignore the input storage
