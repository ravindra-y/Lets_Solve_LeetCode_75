// Approach: Use a Stack to Simulate Asteroid Collisions

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    // Traverse each asteroid
    for (int& a : asteroids) {

      // Collision occurs only when the stack top moves right
      // and the current asteroid moves left.
      while (!st.empty() && a < 0 && st.top() > 0) {
        int sum = a + st.top();

        // Current asteroid is larger, so destroy the stack asteroid.
        if (sum < 0) {
          st.pop();
        }
        // Stack asteroid is larger, so destroy the current asteroid.
        else if (sum > 0) {
          a = 0;
        }
        // Both asteroids have the same size, so both are destroyed.
        else {
          st.pop();
          a = 0;
        }
      }

      // Push the current asteroid if it survives.
      if (a != 0) {
        st.push(a);
      }
    }

    vector<int> result(st.size());

    // Store the surviving asteroids in the correct order.
    for (int i = st.size() - 1; i >= 0; i--) {
      result[i] = st.top();
      st.pop();
    }

    return result;
  }
};

/*
Time Complexity: O(n)
- Traverse the asteroid array once.
- Each asteroid is pushed onto the stack at most once.
- Each asteroid is popped from the stack at most once.
- Overall complexity is O(n).

Space Complexity: O(n)
- In the worst case, no asteroids collide,
  so the stack stores all n asteroids.
*/