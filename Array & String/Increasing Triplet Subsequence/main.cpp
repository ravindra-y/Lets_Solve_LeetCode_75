// Approach: Greedy (Track Smallest and Second Smallest)

class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;

    for (int num : nums) {
      // Update the smallest element seen so far
      if (num <= first) {
        first = num;
      }
      // Update the second smallest element greater than first
      else if (num <= second) {
        second = num;
      }
      // Found an element greater than both first and second
      else {
        return true;
      }
    }

    return false;
  }
};

/*
Time Complexity: O(n)
- Traverse the array only once.
- Each element is processed in constant time.

Space Complexity: O(1)
- Only two variables (first and second) are used.

Where n = nums.size().
*/