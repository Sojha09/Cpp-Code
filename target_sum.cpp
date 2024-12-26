#include <iostream>
#include <vector>
using namespace std;

// This function tries all possible ways to get the target sum
int countWays(vector<int>& nums, int target, int index, int current_sum) {
    // If we've used all numbers in the array
    if (index == nums.size()) {
        // If the current sum equals the target, return 1, otherwise return 0
        return (current_sum == target) ? 1 : 0;
    }

    // Recursively try both adding and subtracting the current number
    int add_ways = countWays(nums, target, index + 1, current_sum + nums[index]);
    int subtract_ways = countWays(nums, target, index + 1, current_sum - nums[index]);

    // Return the total number of ways to achieve the target sum
    return add_ways + subtract_ways;
}

// This function starts the recursive process from the first index
int findTargetSumWays(vector<int>& nums, int target) {
    return countWays(nums, target, 0, 0);  // Start with index 0 and current sum 0
}

int main() {
    // Example: Array with 5 ones, and target sum is 3
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    // Call the function to find the number of ways
    int result = findTargetSumWays(nums, target);
    cout << "Number of ways to achieve target " << target << ": " << result << endl;

    return 0;
}
