// Approach: Two Pointers from Both Ends

class Solution {
public:
  int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int maxWater = 0;

    while (i < j) {
      int length = min(height[i], height[j]);
      int width = j - i;
      int currWater = length * width;

      maxWater = max(maxWater, currWater);

      if (height[i] > height[j]) {
        j--;
      } else {
        i++;
      }
    }

    return maxWater;
  }
};

/*
Time Complexity: O(n)
- Two pointers traverse the array from both ends.
- Each pointer moves inward at most n times.
- Therefore, the array is processed in a single pass.

Space Complexity: O(1)
- Only a few integer variables are used.
- No extra data structures are allocated.
*/