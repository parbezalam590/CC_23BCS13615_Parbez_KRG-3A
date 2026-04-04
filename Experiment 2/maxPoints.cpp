#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
    
    int n = points.size();
    if(n <= 2) return n;

    int ans = 0;

    for(int i = 0; i < n; i++) {
        map<pair<int,int>, int> mp;
        int maxi = 0;

        for(int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            mp[{dx, dy}]++;
            maxi = max(maxi, mp[{dx, dy}]);
        }

        ans = max(ans, maxi + 1); // +1 for base point
    }

    return ans;
}