// Approach: Greedy (Plant Flower When Both Adjacent Plots Are Empty)

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int l = flowerbed.size();

    if (n == 0) return true;

    for (int i = 0; i < l; i++) {
      if (flowerbed[i] == 0) {
        bool check_left = (i == 0) || (flowerbed[i - 1] == 0);
        bool check_right = (i == l - 1) || (flowerbed[i + 1] == 0);

        // Plant a flower if both adjacent plots are empty
        if (check_left && check_right) {
          flowerbed[i] = 1;
          n--;

          // All required flowers have been planted
          if (n == 0) return true;
        }
      }
    }

    return false;
  }
};

/*
Time Complexity: O(n)
- Traverse the flowerbed once.
- Each plot is checked at most one time.

Space Complexity: O(1)
- Only a few variables are used regardless of input size.

Where n = flowerbed.size().
*/