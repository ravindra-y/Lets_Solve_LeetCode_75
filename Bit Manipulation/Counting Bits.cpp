// Approach: Dynamic Programming using right-shift (i >> 1) and least
// significant bit (i & 1)

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> ans(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;
  }
};

/*
Time Complexity: O(n)
- We iterate from 1 to n exactly once.
- Bitwise operations (>> and &) take O(1) time.
- Array lookups take O(1) time.

Space Complexity: O(n)
- An array of size n + 1 is allocated to store the results.
- No extra auxiliary space is used outside of the output vector.

Where n is the given input integer.
*/