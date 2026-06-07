// Approach: Check Common Divisor Pattern + GCD of Lengths

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    // If concatenations differ, no common divisor string exists
    if (str1 + str2 != str2 + str1) return "";

    // Find GCD of the two string lengths
    int g = gcd(str1.size(), str2.size());

    // The first g characters form the largest common divisor string
    return str1.substr(0, g);
  }
};

/*
Time Complexity: O(n + m)
- Creating and comparing (str1 + str2) and (str2 + str1) takes O(n + m).
- Computing GCD of lengths takes O(log(min(n, m))).
- Creating the substring takes O(g), where g is the GCD length.
- Overall complexity is dominated by O(n + m).

Space Complexity: O(n + m)
- Two temporary concatenated strings of length (n + m) are created.
- The returned substring requires O(g) space.
- Overall auxiliary space is O(n + m).

Where:
- n = str1.length()
- m = str2.length()
*/