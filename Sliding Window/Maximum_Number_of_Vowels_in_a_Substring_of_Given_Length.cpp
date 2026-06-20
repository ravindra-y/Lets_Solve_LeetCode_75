// Approach: Sliding Window to Find Maximum Number of Vowels in a Substring of
// Length k

class Solution {
public:
  bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  }

  int maxVowels(string s, int k) {
    int curr = 0;

    for (int i = 0; i < k; i++) {
      if (isVowel(s[i])) curr++;
    }

    int maxVo = curr;

    for (int i = k; i < s.length(); i++) {
      if (isVowel(s[i])) curr++;

      if (isVowel(s[i - k])) curr--;

      maxVo = max(maxVo, curr);
    }

    return maxVo;
  }
};

/*
Time Complexity: O(n)
- Count vowels in the first window in O(k).
- Slide the window through the remaining characters in O(n - k).
- Overall complexity is O(n).

Space Complexity: O(1)
- Only a few variables are used.
- No extra data structures are required.
*/