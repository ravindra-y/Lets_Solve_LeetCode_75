// Approach: Use Recursion (Postorder Traversal)
//
// - If the current node is NULL, return 0.
// - Recursively calculate the maximum depth of the left subtree.
// - Recursively calculate the maximum depth of the right subtree.
// - The depth of the current node is 1 + maximum of left and right depths.
// - Return the calculated depth.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + max(leftDepth, rightDepth);
    }
};

/*
Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(h)
- h is the height of the tree due to the recursion stack.
- Worst Case (Skewed Tree): O(n)
- Best/Average Case (Balanced Tree): O(log n)
*/