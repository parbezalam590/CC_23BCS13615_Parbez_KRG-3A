#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<double> nums(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];   
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i += 3){

        if(i+1 >= n || nums[i] != nums[i+1]){
            cout << "Single element: " << nums[i];
            return 0;
        }
    }

    cout << "Single element: " << nums[n-1];

    return 0;
}