#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power) {

    sort(tokens.begin(), tokens.end());

    int left = 0;                     
    int right = tokens.size() - 1;    

    int score = 0;
    int maxScore = 0;

    while(left <= right) {

        if(power >= tokens[left]) {

            power -= tokens[left];  
            score++;                 
            left++;                  

            maxScore = max(maxScore, score);
        }

        else if(score >= 1) {

            power += tokens[right];  
            score--;                 
            right--;                 
        }

        else {
            break;  
        }
    }

    return maxScore;
}

int main() {

    int n, power;

    cout << "Enter number of tokens: ";
    cin >> n;

    vector<int> tokens(n);

    cout << "Enter tokens: ";
    for(int i = 0; i < n; i++){
        cin >> tokens[i];
    }

    cout << "Enter initial power: ";
    cin >> power;

    int result = bagOfTokensScore(tokens, power);

    cout << "Maximum score: " << result;

    return 0;
}