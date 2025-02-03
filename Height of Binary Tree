class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        // Base case: if the node is null, return -1 (height of an empty tree)
        if (node == nullptr) return -1;
        
        // Recursively find the height of the left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        // Height of the tree is the maximum height of left/right subtree + 1
        return max(leftHeight, rightHeight) + 1;
    }
};
