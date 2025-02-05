class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // Base case: If the tree is empty, do nothing.
        if (node == nullptr) {
            return;
        }

        // Recursively mirror the left and right subtrees.
        mirror(node->left);
        mirror(node->right);

        // Swap the left and right children of the current node.
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};
