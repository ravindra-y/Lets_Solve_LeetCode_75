// Approach: Sort + Two Pointers

class Solution {
public:
  int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int left = 0, right = nums.size() - 1;
    int count = 0;

    while (left < right) {
      int current_sum = nums[left] + nums[right];

      if (current_sum == k) {
        count++;
        left++;
        right--;
      } else if (current_sum < k) {
        left++;
      } else {
        right--;
      }
    }

    return count;
  }
};

/*
Time Complexity: O(n log n)
- Sorting the array takes O(n log n).
- The two-pointer traversal takes O(n).
- Overall complexity is dominated by sorting.

Space Complexity: O(1)
- Only a few variables (left, right, count, current_sum) are used.
- No additional data structures are allocated.
- Ignoring the space used internally by the sorting algorithm.
*/