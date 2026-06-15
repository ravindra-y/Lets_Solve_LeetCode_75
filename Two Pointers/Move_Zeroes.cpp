// Approach: Two Pointers for In-Place Zero Movement

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int nonZero = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        swap(nums[i], nums[nonZero]);
        nonZero++;
      }
    }
  }
};

/*
Time Complexity: O(n)
- Traverse the array once from left to right.
- Each element is visited exactly once.
- Swap operations are performed at most n times.

Space Complexity: O(1)
- The array is modified in-place.
- Only one extra variable (nonZero) is used.
*/