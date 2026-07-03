// Approach: Use Two Queues to Simulate the Voting Process

class Solution {
public:
  string predictPartyVictory(string senate) {

    queue<int> radiant;
    queue<int> dire;

    int n = senate.size();

    // Store indices of both parties
    for (int i = 0; i < n; i++) {
      if (senate[i] == 'R') radiant.push(i);
      else dire.push(i);
    }

    // Simulate voting
    while (!radiant.empty() && !dire.empty()) {

      int r = radiant.front();
      radiant.pop();

      int d = dire.front();
      dire.pop();

      if (r < d) {
        // Radiant bans Dire
        radiant.push(r + n);
      } else {
        // Dire bans Radiant
        dire.push(d + n);
      }
    }

    return radiant.empty() ? "Dire" : "Radiant";
  }
};

/*
Time Complexity: O(n)
- Each senator is added to a queue once.
- Every senator is removed exactly once.
- Hence, the total number of queue operations is linear.

Space Complexity: O(n)
- Two queues store the indices of all senators.
*/