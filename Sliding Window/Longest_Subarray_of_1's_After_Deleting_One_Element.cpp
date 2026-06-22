// Approach: Sliding Window to Find the Longest Subarray of 1s After Deleting
// One Element

class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int i = 0, j = 0;
    int last_zero_idx = -1;
    int result = 0;

    while (j < nums.size()) {
      if (nums[j] == 0) {
        i = last_zero_idx + 1;
        last_zero_idx = j;
      }

      result = max(result, j - i);
      j++;
    }

    return result;
  }
};

/*
Time Complexity: O(n)
- Traverse the array once using the right pointer.
- Overall complexity is O(n).

Space Complexity: O(1)
- Only a few variables are used.
- No extra data structures are required.
*/