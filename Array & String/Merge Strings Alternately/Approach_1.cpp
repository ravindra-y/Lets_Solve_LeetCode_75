// Approach: Two Pointers (Process Both, Then Append Remainder)

class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    string mergedString;

    int i = 0;

    // Add characters alternately while both strings have characters
    while (i < word1.size() && i < word2.size()) {
      mergedString += word1[i];
      mergedString += word2[i];
      i++;
    }

    // Append remaining characters from word1
    while (i < word1.size()) {
      mergedString += word1[i];
      i++;
    }

    // Append remaining characters from word2
    while (i < word2.size()) {
      mergedString += word2[i];
      i++;
    }

    return mergedString;
  }
};

/*
Time Complexity: O(n + m)
- Each character from word1 and word2 is processed exactly once.

Space Complexity: O(n + m)
- The merged string stores all characters from both input strings.
- Here, n = word1.length() and m = word2.length().
*/