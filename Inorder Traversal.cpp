class Solution {
public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> result;
        inOrderRecursive(root, result);
        return result;
    }

private:
    void inOrderRecursive(Node* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }

        inOrderRecursive(node->left, result);  // Traverse left subtree
        result.push_back(node->data);        // Visit the node
        inOrderRecursive(node->right, result); // Traverse right subtree
    }
};
