// Approach: Find Maximum Candy Count, Then Check Each Kid

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int n = candies.size();
    int maxVal = INT_MIN;

    // Find the maximum candies any kid currently has
    for (int i = 0; i < n; i++) {
      if (candies[i] > maxVal) {
        maxVal = candies[i];
      }
    }

    vector<bool> ans;

    // Check if each kid can have the greatest number of candies
    // after receiving extraCandies
    for (int i = 0; i < n; i++) {
      if (candies[i] + extraCandies >= maxVal) {
        ans.push_back(true);
      } else {
        ans.push_back(false);
      }
    }

    return ans;
  }
};

/*
Time Complexity: O(n)
- First traversal finds the maximum candy count.
- Second traversal checks each kid's candies after adding extraCandies.
- Overall, the array is processed twice.

Space Complexity: O(n)
- The result vector stores one boolean value for each kid.
- Here, n = candies.size().
*/