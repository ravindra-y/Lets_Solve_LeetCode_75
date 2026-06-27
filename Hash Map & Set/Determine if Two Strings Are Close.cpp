// Approach: Compare Character Sets and Frequency Counts

class Solution {
public:
  bool closeStrings(string word1, string word2) {

    // Step 1: Length check
    if (word1.size() != word2.size()) return false;

    // Step 2: Store unique characters from both strings
    unordered_set<char> set1(word1.begin(), word1.end());
    unordered_set<char> set2(word2.begin(), word2.end());

    // If character sets are different, strings cannot be close
    if (set1 != set2) return false;

    // Step 3: Count frequency of each character
    unordered_map<char, int> freq1, freq2;

    for (char c : word1)
      freq1[c]++;
    for (char c : word2)
      freq2[c]++;

    vector<int> f1, f2;

    // Store frequency counts in vectors
    for (auto& p : freq1)
      f1.push_back(p.second);
    for (auto& p : freq2)
      f2.push_back(p.second);

    // Step 4: Sort frequency arrays
    sort(f1.begin(), f1.end());
    sort(f2.begin(), f2.end());

    // Step 5: Compare sorted frequencies
    return f1 == f2;
  }
};

/*
Time Complexity: O(n + k log k)
- Checking string lengths takes O(1).
- Creating two unordered_sets takes O(n).
- Building two frequency maps takes O(n).
- Copying frequencies into vectors takes O(k).
- Sorting both frequency vectors takes O(k log k).

Overall: O(n + k log k)

where:
- n = length of the strings
- k = number of distinct characters (at most 26 for lowercase English letters)

Space Complexity: O(k)
- Two unordered_sets store unique characters.
- Two unordered_maps store character frequencies.
- Two vectors store the frequency counts.
*/