// Approach: Reverse Linked List Using Recursion
//
// - If the list is empty or contains only one node,
//   it is already reversed, so return it.
// - Recursively reverse the remaining list starting
//   from head->next.
// - After the recursive call returns:
//      head->next->next = head;
//   This makes the next node point back to the current node.
// - Break the original forward link by setting:
//      head->next = NULL;
// - Return the new head (last node of the original list).

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    // Base Case: Empty list or single node
    if (head == NULL || head->next == NULL) return head;

    // Reverse the rest of the list
    ListNode* last = reverseList(head->next);

    // Reverse the current connection
    head->next->next = head;
    head->next = NULL;

    return last;
  }
};

/*
Time Complexity: O(n)
- Each node is visited exactly once during the recursive calls.
- Overall time complexity is linear.

Space Complexity: O(n)
- The recursion stack stores one function call for each node.
- In the worst case, the recursion depth is n.
*/