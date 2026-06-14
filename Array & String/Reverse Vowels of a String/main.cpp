// Approach: Two Pointers to Swap Vowels from Both Ends

class Solution {
public:
  bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }

  string reverseVowels(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {

      while (left < right && !isVowel(s[left]))
        left++;

      while (left < right && !isVowel(s[right]))
        right--;

      swap(s[left], s[right]);

      left++;
      right--;
    }

    return s;
  }
};

/*
Time Complexity: O(n)
- Use two pointers moving toward each other.
- Each character is visited at most once by either pointer.
- Vowel checking takes O(1) time.

Space Complexity: O(1)
- Reversal is performed in-place.
- Only two pointers and a few temporary variables are used.

Where n = s.length().
*/