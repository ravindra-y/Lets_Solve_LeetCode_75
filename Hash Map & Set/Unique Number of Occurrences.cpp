// Approach: Use HashMap to Count Frequencies and HashSet to Check Unique
// Occurrences

class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> freq;

    // Count occurrences of each element
    for (int n : arr) {
      freq[n]++;
    }

    unordered_set<int> seen;

    // Check if all occurrence counts are unique
    for (auto x : freq) {
      if (seen.count(x.second)) return false;

      seen.insert(x.second);
    }

    return true;
  }
};

/*
Time Complexity: O(n) (Average Case)
- Counting frequencies using unordered_map takes O(n).
- Traversing the frequency map takes O(k), where k is the number of distinct
elements.
- Each unordered_set lookup/insertion is O(1) on average.
- Overall: O(n).

Space Complexity: O(k)
- unordered_map stores the frequency of each distinct element.
- unordered_set stores the occurrence counts.
- Here, k is the number of distinct elements.
*/