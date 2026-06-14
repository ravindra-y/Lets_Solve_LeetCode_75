// Approach: Reverse Entire String, Then Reverse Each Word and Remove Extra
// Spaces

class Solution {
public:
  string reverseWords(string s) {
    reverse(s.begin(), s.end());

    int i = 0;
    int l = 0, r = 0;

    int n = s.length();

    while (i < n) {
      while (i < n && s[i] == ' ')
        i++;

      while (i < n && s[i] != ' ') {
        s[r++] = s[i++];
      }

      if (l < r) {
        reverse(s.begin() + l, s.begin() + r);

        s[r++] = ' ';
        l = r;
      }
    }

    s = s.substr(0, r - 1);

    return s;
  }
};

/*
Time Complexity: O(n)
- Reverse the entire string once.
- Traverse the string once to process words.
- Reverse each word once.
- Each character is visited a constant number of times.

Space Complexity: O(1)
- All operations are performed in-place on the input string.
- Only a few extra variables are used.

Where n = s.length().
*/