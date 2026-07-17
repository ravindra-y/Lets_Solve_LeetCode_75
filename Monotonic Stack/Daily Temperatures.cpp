// Approach: Monotonic Stack to Find Next Greater Element

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();

    // Default wait time is 0
    vector<int> answer(n, 0);

    // Stores indices of days
    stack<int> s;

    for (int i = 0; i < n; i++) {
      // Found a warmer day
      while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
        int prevDay = s.top();

        // Remove resolved day
        s.pop();

        // Calculate wait time
        answer[prevDay] = i - prevDay;
      }

      // Save current day to resolve later
      s.push(i);
    }

    return answer;
  }
};

/*
Time Complexity: O(n)
- Traverse the array once.
- Each index is pushed and popped at most once.

Space Complexity: O(n)
- Stack stores at most n indices.
- Answer array takes O(n) space.
*/