// Approach: Store Values in a Vector and Use Two Pointers
//
// - Traverse the linked list and store each node's value in a vector.
// - Use two pointers:
//   - i starts from the beginning of the vector.
//   - j starts from the end of the vector.
// - Since twin nodes are equidistant from the ends, pair:
//       val[i] with val[j]
// - Calculate the sum of each twin pair and keep track of the maximum sum.
// - Continue until the two pointers meet or cross.

class Solution {
public:
  int pairSum(ListNode* head) {
    vector<int> val;

    ListNode* curr = head;

    // Store all node values
    while (curr != NULL) {
      val.push_back(curr->val);
      curr = curr->next;
    }

    int i = 0, j = val.size() - 1;
    int maxSum = 0;

    // Find the maximum twin sum
    while (i < j) {
      maxSum = max(maxSum, val[i] + val[j]);
      i++;
      j--;
    }

    return maxSum;
  }
};

/*
Time Complexity: O(n)
- Traverse the linked list once to store all values in the vector.
- Traverse the vector once using two pointers to compute the maximum twin sum.
- Overall time complexity is linear.

Space Complexity: O(n)
- An extra vector is used to store all node values.
- The vector requires O(n) additional space.
*/