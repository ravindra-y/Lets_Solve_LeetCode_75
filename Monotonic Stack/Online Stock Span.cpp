// Approach: Monotonic Stack
class StockSpanner {
public:
  stack<pair<int, int>> st; // pair of {price, span}
  StockSpanner() {}

  int next(int price) {
    int span = 1; // currently span of price is 1 which is itself

    // Accumulate spans of all previous days with smaller or equal prices
    while (!st.empty() && st.top().first <= price) {
      span = span + st.top().second;
      st.pop();
    }

    st.push({price, span});

    return span;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/*
Time Complexity: O(1) Amortized - Each price is pushed and popped from the stack
at most once across all calls. Space Complexity: O(N) - In the worst case
(strictly decreasing prices), the stack stores all N prices.
*/