//BRUTE FORCE APPROACH : Time - O(N^2) , Space - O(1)
#include <bits/stdc++.h>
using namespace std;

int differentBitsSumPairwise(vector<int> &A) {
    const int MOD = 1e9 + 7;
    int n = A.size();
    long long ans = 0;

    // Check all pairs (i, j)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            // XOR gives differing bits
            int xorVal = A[i] ^ A[j];

            // Count set bits using built-in function
            ans += __builtin_popcount(xorVal);
            ans %= MOD;
        }
    }

    return ans;
}
//COMPLEXITY : Time - O(N² * 32) , Space - O(1)

//OPTIMISED APPROACH

#include <bits/stdc++.h>
using namespace std;

int differentBitsSumPairwise(vector<int> &A) {
    const int MOD = 1e9 + 7;
    int n = A.size();
    long long ans = 0;

    // Loop through all 32 bits
    for (int bit = 0; bit < 32; bit++) {

        long long count1 = 0;

        // Count numbers having this bit set
        for (int i = 0; i < n; i++) {
            if (A[i] & (1LL << bit)) {
                count1++;
            }
        }

        long long count0 = n - count1;

        // Each differing pair contributes 1
        // Multiply by 2 for ordered pairs
        long long contribution = (2LL * count1 % MOD * count0 % MOD) % MOD;

        ans = (ans + contribution) % MOD;
    }

    return ans;
}

//COMPLEXITY : Time - O(N * 32) , Space - O(1)