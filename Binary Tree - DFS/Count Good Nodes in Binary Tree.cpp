// Approach: Use DFS (Preorder Traversal)
//
// - Start traversing the tree from the root while keeping track of the
//   maximum value seen on the path from the root to the current node.
// - If the current node's value is greater than or equal to the maximum
//   value seen so far, it is a good node, so count it.
// - Update the maximum value for the current path.
// - Recursively traverse the left and right subtrees.
// - Return the total number of good nodes found.

class Solution {
public:
  int dfs(TreeNode* root, int maxVal) {
    if (!root) return 0;

    int good = 0;

    if (root->val >= maxVal) {
      good = 1;
      maxVal = root->val;
    }

    good += dfs(root->left, maxVal);
    good += dfs(root->right, maxVal);

    return good;
  }

  int goodNodes(TreeNode* root) {
    return dfs(root, root->val);
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