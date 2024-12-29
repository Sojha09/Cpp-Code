//Problem:Intersection of 2 Array with Duplicate Items
//Author: Shubham Ojha
//Date:29-12-24
#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> freqMap;  // Map to store frequency of elements in nums1
    vector<int> result;  // Vector to store the result of intersection

    // Step 1: Count frequency of each element in nums1
    for (int num : nums1) {
        freqMap[num]++;
    }

    // Step 2: Iterate through nums2 and check for intersection
    for (int num : nums2) {
        if (freqMap[num] > 0) {  // If the element exists in nums1 and has a non-zero count
            result.push_back(num);  // Add it to the result
            freqMap[num]--;  // Decrease the count to handle duplicates
        }
    }

    return result;  // Return the result
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> intersection = intersect(nums1, nums2);

    // Output the result
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
