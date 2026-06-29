// Approach: Use a String as a Stack

class Solution {
public:
  string removeStars(string s) {

    string stack;

    // Traverse each character
    for (char c : s) {

      // If '*' is found, remove the most recent character
      if (c == '*') {
        stack.pop_back();
      }
      // Otherwise, add the current character
      else {
        stack.push_back(c);
      }
    }

    return stack;
  }
};

/*
Time Complexity: O(n)
- Traverse the string once.
- Each push_back() and pop_back() operation takes O(1).
- Overall complexity is O(n).

Space Complexity: O(n)
- In the worst case (when there are no '*'),
  the stack stores all characters of the input string.
*/