// Approach: Sliding Window to Find the Longest Subarray with At Most k Zeros

class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int left = 0;
    int zeroCount = 0;
    int maxLen = 0;

    for (int right = 0; right < nums.size(); right++) {
      if (nums[right] == 0) {
        zeroCount++;
      }

      // Shrink the window until it contains at most k zeros
      while (zeroCount > k) {
        if (nums[left] == 0) {
          zeroCount--;
        }
        left++;
      }

      maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
  }
};

/*
Time Complexity: O(n)
- The right pointer traverses the array once.
- The left pointer also moves forward at most n times.
- Each element is processed at most twice.
- Overall complexity is O(n).

Space Complexity: O(1)
- Only a few variables (left, right, zeroCount, maxLen) are used.
- No extra data structures are required.
*/