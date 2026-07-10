// Approach: Use DFS to Collect Leaf Nodes
//
// - Traverse both trees using recursion.
// - If the current node is NULL, return.
// - If the current node is a leaf, append its value to the string and return.
// - Otherwise, recursively traverse the left subtree followed by the right
// subtree.
// - Repeat the process for both trees.
// - Compare the generated leaf sequences.
// - If both sequences are identical, return true; otherwise, return false.

class Solution {
public:
  void inOrder(TreeNode* root, string& s) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
      s += to_string(root->val) + "_";
      return;
    }

    inOrder(root->left, s);
    inOrder(root->right, s);
  }

  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    string s1 = "";
    string s2 = "";

    inOrder(root1, s1);
    inOrder(root2, s2);

    return s1 == s2;
  }
};

/*
Time Complexity: O(n + m)
- n = Number of nodes in the first tree.
- m = Number of nodes in the second tree.
- Every node in both trees is visited exactly once.

Space Complexity: O(h1 + h2)
- h1 is the height of the first tree.
- h2 is the height of the second tree.
- Due to the recursion stack.
- Worst Case (Skewed Trees): O(n + m)
- Best/Average Case (Balanced Trees): O(log n + log m)

Note:
- The strings storing the leaf sequences require additional space proportional
  to the number of leaf nodes.
*/