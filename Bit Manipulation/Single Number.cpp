// Approach: Bit Manipulation using XOR
//
// - Initialize ans = 0.
// - Traverse the array and XOR every element with ans.
// - XOR of two same numbers is 0 (a ^ a = 0), so all duplicate
//   elements cancel each other.
// - XOR of any number with 0 is the number itself (a ^ 0 = a).
// - After processing all elements, only the element that appears
//   once remains in ans.

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (int val : nums) {
      ans ^= val;
    }

    return ans;
  }
};

/*
Time Complexity: O(n)
- We traverse the array exactly once.
- Each XOR operation takes O(1) time.

Space Complexity: O(1)
- Only one integer variable (ans) is used.
- No extra data structures are required.

Where n is the number of elements in the array.
*/