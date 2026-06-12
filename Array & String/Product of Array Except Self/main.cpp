// Approach: Prefix and Suffix Product in a Single Traversal

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    int prefix = 1, suffix = 1;

    for (int i = 0; i < n; i++) {
      result[i] *= prefix;
      prefix *= nums[i];

      result[n - 1 - i] *= suffix;
      suffix *= nums[n - 1 - i];
    }

    return result;
  }
};

/*
Time Complexity: O(n)
- Traverse the array once.
- Each element contributes to both prefix and suffix calculations.

Space Complexity: O(1)
- Excluding the output array.
- Only two extra variables (prefix and suffix) are used.

Where n = nums.size().
*/