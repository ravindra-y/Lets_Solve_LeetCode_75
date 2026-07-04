// Approach: Slow and Fast Pointers to Delete the Middle Node
//
// - Use two pointers:
//   - slow moves one step at a time.
//   - fast moves two steps at a time.
// - Keep a 'prev' pointer to track the node before 'slow'.
// - When 'fast' reaches the end of the list, 'slow' will be at the middle node.
// - Delete the middle node by linking:
//       prev->next = slow->next;

class Solution {
public:
  ListNode* deleteMiddle(ListNode* head) {
    // Edge Case: If the list is empty or has only one node
    if (head == nullptr || head->next == nullptr) {
      return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    // Find the middle node while keeping track of the previous node
    while (fast != nullptr && fast->next != nullptr) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    // Remove the middle node
    prev->next = slow->next;

    return head;
  }
};

/*
Time Complexity: O(n)
- Traverse the linked list only once using slow and fast pointers.
- The fast pointer reaches the end after approximately n/2 iterations.
- Overall time complexity is linear.

Space Complexity: O(1)
- Only three pointers (slow, fast, and prev) are used.
- No extra data structures are required.
*/