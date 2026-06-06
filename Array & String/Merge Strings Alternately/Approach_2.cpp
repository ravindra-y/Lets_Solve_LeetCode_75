// Approach: Single Loop (Optimal and Cleaner)

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string mergedString;

    int maxLen = max(word1.size(), word2.size());

    for (int i = 0; i < maxLen; i++) {
      // Add from word1 if characters remain
      if (i < word1.size()) {
        mergedString += word1[i];
      }

      // Add from word2 if characters remain
      if (i < word2.size()) {
        mergedString += word2[i];
      }
    }

    return mergedString;
  }
};

/*
Time Complexity: O(max(n, m))
- The loop runs max(n, m) times.
- Each iteration performs constant-time operations.

Space Complexity: O(n + m)
- The merged string stores all characters from both input strings.
- Here, n = word1.length() and m = word2.length().
*/