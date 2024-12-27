//Problem: Best SightSeeing Pair
//Author: Shubham Ojha
//Date:27-12-24

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
    int ans = 0;
    int maxVal = values[0]; // Start with the first value + its index
    
    for (int j = 1; j < values.size(); j++) {
        // Calculate score using maxVal (which stores the best values[i] + i so far)
        ans = max(ans, maxVal + values[j] - j);
        
        // Update maxVal to include the current value + its index
        maxVal = max(maxVal, values[j] + j);
    }
    
    return ans;
}

int main() {
    vector<int> values = {8, 1, 5, 2, 6};
    
    // Calling the function and printing the result
    int result = maxScoreSightseeingPair(values);
    // Expected output: 11, since the pair (values[0], values[2]) gives the maximum score
    // (8 + 1 + 5 - 2 = 11)
    cout << "Max Score Sightseeing Pair: " << result << endl;
    
    return 0;
}

