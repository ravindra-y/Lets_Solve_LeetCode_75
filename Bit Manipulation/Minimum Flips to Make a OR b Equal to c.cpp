// Approach: Bitwise Evaluation
//
// - Initialize flips = 0.
// - Loop while a > 0, b > 0, or c > 0.
// - Extract the least significant bit (LSB) of a, b, and c using bitwise AND (&
// 1).
// - If the target bit in c is 1, check if both bits in a and b are 0. If so,
// increment flips by 1.
// - If the target bit in c is 0, add the sum of bits in a and b to flips (since
// both must be 0).
// - Right shift a, b, and c by 1 to process the next bit.
// - Return total flips.

class Solution {
public:
  int minFlips(int a, int b, int c) {
    int flips = 0;

    while (a > 0 || b > 0 || c > 0) {
      int bit_a = a & 1;
      int bit_b = b & 1;
      int bit_c = c & 1;

      if (bit_c == 1) {
        if (bit_a == 0 && bit_b == 0) {
          flips++;
        }
      } else {
        flips += (bit_a + bit_b);
      }

      a >>= 1;
      b >>= 1;
      c >>= 1;
    }

    return flips;
  }
};

/*
Time Complexity: O(log(max(a, b, c)))
- We iterate through the bits of the largest number.
- Since the inputs are 32-bit integers, this loop runs at most 32 times, making
it effectively O(1).

Space Complexity: O(1)
- Only a few integer variables are used.
- No extra data structures are required.

Where the numbers are bounded by 32 bits.
*/