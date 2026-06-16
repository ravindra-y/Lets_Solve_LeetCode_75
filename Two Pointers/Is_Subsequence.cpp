// Approach: Two Pointers for Subsequence Matching

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int i = 0, j = 0;

    while (i < s.size() && j < t.size()) {
      if (s[i] == t[j]) {
        i++;
      }
      j++;
    }

    return i == s.size();
  }
};

/*
Time Complexity: O(n)
- Traverse string t only once using pointer j.
- Each character in t is visited at most once.
- Here, n = t.size().

Space Complexity: O(1)
- Only two pointer variables (i and j) are used.
- No extra data structures are allocated.
*/