// Approach: Store All Rows in a Map and Compare with Each Column

class Solution {
public:
  int equalPairs(vector<vector<int>>& grid) {

    int n = grid.size();
    map<vector<int>, int> rowCount;

    // Store the frequency of every row
    for (int i = 0; i < n; i++) {
      rowCount[grid[i]]++;
    }

    int ans = 0;

    // Build each column and check if it matches any stored row
    for (int c = 0; c < n; c++) {
      vector<int> col;

      for (int r = 0; r < n; r++) {
        col.push_back(grid[r][c]);
      }

      if (rowCount.count(col)) {
        ans += rowCount[col];
      }
    }

    return ans;
  }
};

/*
Time Complexity: O(n² log n)
- Storing all rows in the map takes O(n² log n).
- Constructing all columns takes O(n²).
- Each map lookup takes O(log n), performed n times.
- Overall complexity is O(n² log n).

Space Complexity: O(n²)
- The map stores n row vectors, each of size n.
- An additional column vector of size n is used during traversal.
*/