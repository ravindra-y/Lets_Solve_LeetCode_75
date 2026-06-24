// Approach: Use Total Sum and Running Left Sum (Prefix Sum Idea)

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int totalSum = 0;

    for (int num : nums) {
      totalSum += num;
    }

    int leftSum = 0;

    for (int i = 0; i < nums.size(); i++) {
      int rightSum = totalSum - leftSum - nums[i];

      if (leftSum == rightSum) {
        return i;
      }

      leftSum += nums[i];
    }

    return -1;
  }
};

/*
Time Complexity: O(n)
- First pass calculates the total sum.
- Second pass checks each index as a potential pivot.
- Total work is proportional to the size of the array.

Space Complexity: O(1)
- Only a few integer variables are used.
- No extra arrays or data structures are required.
*/