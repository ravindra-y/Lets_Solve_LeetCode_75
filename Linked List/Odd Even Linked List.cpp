// Approach: Separate Odd and Even Indexed Nodes
//
// - Use two pointers:
//   - odd points to the odd-indexed nodes.
//   - even points to the even-indexed nodes.
// - Store the head of the even list (evenHead) so it can be attached later.
// - Rearrange the next pointers:
//     - Connect each odd node to the next odd node.
//     - Connect each even node to the next even node.
// - Once all nodes are separated, connect the last odd node to evenHead.

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {

    // Edge Case: Empty list or only one node
    if (head == NULL || head->next == NULL) return head;

    ListNode* odd = head;
    ListNode* even = head->next;

    // Store the starting node of the even list
    ListNode* evenHead = even;

    // Separate odd and even indexed nodes
    while (even != NULL && even->next != NULL) {
      odd->next = even->next;
      even->next = even->next->next;

      odd = odd->next;
      even = even->next;
    }

    // Connect the odd list with the even list
    odd->next = evenHead;

    return head;
  }
};

/*
Time Complexity: O(n)
- Traverse the linked list only once.
- Each node is visited exactly once.
- Overall time complexity is linear.

Space Complexity: O(1)
- Only a few pointers (odd, even, and evenHead) are used.
- No extra data structures are required.
*/