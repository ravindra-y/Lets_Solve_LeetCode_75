// Approach: Two Pointers for In-Place String Compression

class Solution {
public:
  int compress(vector<char>& chars) {
    int index = 0; // write pointer
    int i = 0;     // read pointer

    while (i < chars.size()) {
      char currentChar = chars[i];
      int count = 0;

      // Count occurrences of the current character
      while (i < chars.size() && chars[i] == currentChar) {
        i++;
        count++;
      }

      // Write the character
      chars[index++] = currentChar;

      // Write count digits if frequency > 1
      if (count > 1) {
        for (char c : to_string(count)) {
          chars[index++] = c;
        }
      }
    }

    return index;
  }
};

/*
Time Complexity: O(n)
- Traverse the array once using the read pointer.
- Each character is processed exactly once.
- Writing count digits across all groups is bounded by the total number of
characters.

Space Complexity: O(1)
- Compression is performed in-place.
- Only a few extra variables (index, i, count, currentChar) are used.

Where n = chars.size().
*/