// Approach: Use a Queue to Store Recent Requests

class RecentCounter {
  queue<int> q;

public:
  RecentCounter() {}

  int ping(int t) {

    // Add the current request timestamp
    q.push(t);

    // Remove requests older than (t - 3000)
    while (q.front() < t - 3000) {
      q.pop();
    }

    // Remaining requests are within the last 3000ms
    return q.size();
  }
};

/*
Time Complexity: O(1) Amortized
- Each timestamp is inserted into the queue once.
- Each timestamp is removed from the queue at most once.
- Therefore, across all calls to ping(), the total work is linear,
  making each operation O(1) amortized.

Space Complexity: O(n)
- The queue stores only the timestamps within the last 3000ms.
- In the worst case, all requests fall within this range.
*/